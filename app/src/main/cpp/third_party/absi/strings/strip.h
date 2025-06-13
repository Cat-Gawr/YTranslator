//
#ifndef ABSL_STRINGS_STRIP_H_
#define ABSL_STRINGS_STRIP_H_

#include <string>

#include "third_party/absl/strings/match.h"

namespace absl {

inline bool ConsumePrefix(absl::string_view *str, absl::string_view expected) {
  if (!absl::StartsWith(*str, expected)) return false;
  str->remove_prefix(expected.size());
  return true;
}

}  // namespace absl
#endif  // ABSL_STRINGS_STRIP_H
