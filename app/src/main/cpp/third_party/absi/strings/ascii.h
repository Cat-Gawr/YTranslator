//

#ifndef ABSL_STRINGS_ASCII_H_
#define ABSL_STRINGS_ASCII_H_

#include <ctype.h>

#include <string>

#include "third_party/absl/strings/string_view.h"

namespace absl {

inline std::string AsciiStrToUpper(absl::string_view value) {
  std::string upper_value = std::string(value);
  std::transform(upper_value.begin(), upper_value.end(), upper_value.begin(),
                 ::toupper);
  return upper_value;
}

inline std::string AsciiStrToLower(absl::string_view value) {
  std::string lower_value = std::string(value);
  std::transform(lower_value.begin(), lower_value.end(), lower_value.begin(),
                 ::tolower);
  return lower_value;
}
}  // namespace absl
#endif  // ABSL_STRINGS_ASCII_H_
