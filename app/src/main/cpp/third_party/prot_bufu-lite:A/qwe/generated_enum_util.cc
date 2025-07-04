#include <google/protobuf/generated_enum_util.h>

#include <algorithm>

#include <google/protobuf/generated_message_util.h>

namespace google {
namespace protobuf {
namespace internal {
namespace {

bool EnumCompareByName(const EnumEntry& a, const EnumEntry& b) {
  return StringPiece(a.name) < StringPiece(b.name);
}

// Gets the numeric value of the EnumEntry at the given index, but returns a
// special value for the index -1. This gives a way to use std::lower_bound on a
// sorted array of indices while searching for value that we associate with -1.
int GetValue(const EnumEntry* enums, int i, int target) {
  if (i == -1) {
    return target;
  } else {
    return enums[i].value;
  }
}

}  // namespace

bool LookUpEnumValue(const EnumEntry* enums, size_t size,
                     StringPiece name, int* value) {
  EnumEntry target{name, 0};
  auto it = std::lower_bound(enums, enums + size, target, EnumCompareByName);
  if (it != enums + size && it->name == name) {
    *value = it->value;
    return true;
  }
  return false;
}

int LookUpEnumName(const EnumEntry* enums, const int* sorted_indices,
                   size_t size, int value) {
  auto comparator = [enums, value](int a, int b) {
    return GetValue(enums, a, value) < GetValue(enums, b, value);
  };
  auto it =
      std::lower_bound(sorted_indices, sorted_indices + size, -1, comparator);
  if (it != sorted_indices + size && enums[*it].value == value) {
    return it - sorted_indices;
  }
  return -1;
}

bool InitializeEnumStrings(
    const EnumEntry* enums, const int* sorted_indices, size_t size,
    internal::ExplicitlyConstructed<std::string>* enum_strings) {
  for (int i = 0; i < size; ++i) {
    enum_strings[i].Construct(enums[sorted_indices[i]].name);
    internal::OnShutdownDestroyString(enum_strings[i].get_mutable());
  }
  return true;
}

}  // namespace internal
}  // namespace protobuf
}  // namespace google
