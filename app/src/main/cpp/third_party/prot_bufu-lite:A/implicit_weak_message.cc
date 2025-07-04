#include <google/protobuf/implicit_weak_message.h>

#include <google/protobuf/parse_context.h>
#include <google/protobuf/io/zero_copy_stream_impl_lite.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/wire_format_lite.h>

#include <google/protobuf/port_def.inc>

namespace google {
namespace protobuf {
namespace internal {

const char* ImplicitWeakMessage::_InternalParse(const char* ptr,
                                                ParseContext* ctx) {
  return ctx->AppendString(ptr, &data_);
}

ExplicitlyConstructed<ImplicitWeakMessage>
    implicit_weak_message_default_instance;
internal::once_flag implicit_weak_message_once_init_;

void InitImplicitWeakMessageDefaultInstance() {
  implicit_weak_message_default_instance.DefaultConstruct();
}

const ImplicitWeakMessage* ImplicitWeakMessage::default_instance() {
  internal::call_once(implicit_weak_message_once_init_,
                      InitImplicitWeakMessageDefaultInstance);
  return &implicit_weak_message_default_instance.get();
}

}  // namespace internal
}  // namespace protobuf
}  // namespace google
