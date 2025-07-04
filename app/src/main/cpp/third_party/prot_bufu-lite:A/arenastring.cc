#include <google/protobuf/arenastring.h>

#include <google/protobuf/stubs/logging.h>
#include <google/protobuf/stubs/common.h>
#include <google/protobuf/parse_context.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/stubs/mutex.h>
#include <google/protobuf/stubs/strutil.h>
#include <google/protobuf/stubs/stl_util.h>

// clang-format off
#include <google/protobuf/port_def.inc>
// clang-format on

namespace google {
namespace protobuf {
namespace internal {

const std::string& LazyString::Init() const {
  static WrappedMutex mu{GOOGLE_PROTOBUF_LINKER_INITIALIZED};
  mu.Lock();
  const std::string* res = inited_.load(std::memory_order_acquire);
  if (res == nullptr) {
    auto init_value = init_value_;
    res = ::new (static_cast<void*>(string_buf_))
        std::string(init_value.ptr, init_value.size);
    inited_.store(res, std::memory_order_release);
  }
  mu.Unlock();
  return *res;
}


void ArenaStringPtr::Set(const std::string* default_value,
                         ConstStringParam value, ::google::protobuf::Arena* arena) {
  if (IsDefault(default_value)) {
    tagged_ptr_.Set(Arena::Create<std::string>(arena, value));
  } else {
    UnsafeMutablePointer()->assign(value.data(), value.length());
  }
}

void ArenaStringPtr::Set(const std::string* default_value, std::string&& value,
                         ::google::protobuf::Arena* arena) {
  if (IsDefault(default_value)) {
    if (arena == nullptr) {
      tagged_ptr_.Set(new std::string(std::move(value)));
    } else {
      tagged_ptr_.Set(Arena::Create<std::string>(arena, std::move(value)));
    }
  } else if (IsDonatedString()) {
    std::string* current = tagged_ptr_.Get();
    auto* s = new (current) std::string(std::move(value));
    arena->OwnDestructor(s);
    tagged_ptr_.Set(s);
  } else /* !IsDonatedString() */ {
    *UnsafeMutablePointer() = std::move(value);
  }
}

void ArenaStringPtr::Set(EmptyDefault, ConstStringParam value,
                         ::google::protobuf::Arena* arena) {
  Set(&GetEmptyStringAlreadyInited(), value, arena);
}

void ArenaStringPtr::Set(EmptyDefault, std::string&& value,
                         ::google::protobuf::Arena* arena) {
  Set(&GetEmptyStringAlreadyInited(), std::move(value), arena);
}

void ArenaStringPtr::Set(NonEmptyDefault, ConstStringParam value,
                         ::google::protobuf::Arena* arena) {
  Set(nullptr, value, arena);
}

void ArenaStringPtr::Set(NonEmptyDefault, std::string&& value,
                         ::google::protobuf::Arena* arena) {
  Set(nullptr, std::move(value), arena);
}

std::string* ArenaStringPtr::Mutable(EmptyDefault, ::google::protobuf::Arena* arena) {
  if (!IsDonatedString() && !IsDefault(&GetEmptyStringAlreadyInited())) {
    return UnsafeMutablePointer();
  } else {
    return MutableSlow(arena);
  }
}

std::string* ArenaStringPtr::Mutable(const LazyString& default_value,
                                     ::google::protobuf::Arena* arena) {
  if (!IsDonatedString() && !IsDefault(nullptr)) {
    return UnsafeMutablePointer();
  } else {
    return MutableSlow(arena, default_value);
  }
}

std::string* ArenaStringPtr::MutableNoCopy(const std::string* default_value,
                                           ::google::protobuf::Arena* arena) {
  if (!IsDonatedString() && !IsDefault(default_value)) {
    return UnsafeMutablePointer();
  } else {
    GOOGLE_DCHECK(IsDefault(default_value));
    // Allocate empty. The contents are not relevant.
    std::string* new_string = Arena::Create<std::string>(arena);
    tagged_ptr_.Set(new_string);
    return new_string;
  }
}

template <typename... Lazy>
std::string* ArenaStringPtr::MutableSlow(::google::protobuf::Arena* arena,
                                         const Lazy&... lazy_default) {
  const std::string* const default_value =
      sizeof...(Lazy) == 0 ? &GetEmptyStringAlreadyInited() : nullptr;
  GOOGLE_DCHECK(IsDefault(default_value));
  std::string* new_string =
      Arena::Create<std::string>(arena, lazy_default.get()...);
  tagged_ptr_.Set(new_string);
  return new_string;
}

std::string* ArenaStringPtr::Release(const std::string* default_value,
                                     ::google::protobuf::Arena* arena) {
  if (IsDefault(default_value)) {
    return nullptr;
  } else {
    return ReleaseNonDefault(default_value, arena);
  }
}

std::string* ArenaStringPtr::ReleaseNonDefault(const std::string* default_value,
                                               ::google::protobuf::Arena* arena) {
  GOOGLE_DCHECK(!IsDefault(default_value));

  if (!IsDonatedString()) {
    std::string* released;
    if (arena != nullptr) {
      released = new std::string;
      released->swap(*UnsafeMutablePointer());
    } else {
      released = UnsafeMutablePointer();
    }
    tagged_ptr_.Set(const_cast<std::string*>(default_value));
    return released;
  } else /* IsDonatedString() */ {
    GOOGLE_DCHECK(arena != nullptr);
    std::string* released = new std::string(Get());
    tagged_ptr_.Set(const_cast<std::string*>(default_value));
    return released;
  }
}

void ArenaStringPtr::SetAllocated(const std::string* default_value,
                                  std::string* value, ::google::protobuf::Arena* arena) {
  // Release what we have first.
  if (arena == nullptr && !IsDefault(default_value)) {
    delete UnsafeMutablePointer();
  }
  if (value == nullptr) {
    tagged_ptr_.Set(const_cast<std::string*>(default_value));
  } else {
#ifdef NDEBUG
    tagged_ptr_.Set(value);
    if (arena != nullptr) {
      arena->Own(value);
    }
#else
    // On debug builds, copy the string so the address differs.  delete will
    // fail if value was a stack-allocated temporary/etc., which would have
    // failed when arena ran its cleanup list.
    std::string* new_value = Arena::Create<std::string>(arena, *value);
    delete value;
    tagged_ptr_.Set(new_value);
#endif
  }
}

void ArenaStringPtr::Destroy(const std::string* default_value,
                             ::google::protobuf::Arena* arena) {
  if (arena == nullptr) {
    GOOGLE_DCHECK(!IsDonatedString());
    if (!IsDefault(default_value)) {
      delete UnsafeMutablePointer();
    }
  }
}

void ArenaStringPtr::Destroy(EmptyDefault, ::google::protobuf::Arena* arena) {
  Destroy(&GetEmptyStringAlreadyInited(), arena);
}

void ArenaStringPtr::Destroy(NonEmptyDefault, ::google::protobuf::Arena* arena) {
  Destroy(nullptr, arena);
}

void ArenaStringPtr::ClearToEmpty() {
  if (IsDefault(&GetEmptyStringAlreadyInited())) {
    // Already set to default -- do nothing.
  } else {
    // Unconditionally mask away the tag.
    //
    // UpdateDonatedString uses assign when capacity is larger than the new
    // value, which is trivially true in the donated string case.
    // const_cast<std::string*>(PtrValue<std::string>())->clear();
    tagged_ptr_.Get()->clear();
  }
}

void ArenaStringPtr::ClearToDefault(const LazyString& default_value,
                                    ::google::protobuf::Arena* arena) {
  (void)arena;
  if (IsDefault(nullptr)) {
    // Already set to default -- do nothing.
  } else if (!IsDonatedString()) {
    UnsafeMutablePointer()->assign(default_value.get());
  }
}


}  // namespace internal
}  // namespace protobuf
}  // namespace google
