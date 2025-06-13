#ifndef ABSL_STRINGS_NUMBERS_H_
#define ABSL_STRINGS_NUMBERS_H_

#include <sstream>

#include "third_party/absl/strings/string_view.h"

namespace absl {

// TODO(taku): Re-implement this, as it is slow.
template <typename T>
inline bool SimpleAtoi(absl::string_view s, T *result) {
  std::stringstream ss;
  return (ss << s.data() && ss >> *result);
}

}  // namespace absl
#endif  // ABSL_STRINGS_NUMBERS_H_
