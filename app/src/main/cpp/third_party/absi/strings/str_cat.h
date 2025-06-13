//
#ifndef ABSL_STRINGS_STR_CAT_H_
#define ABSL_STRINGS_STR_CAT_H_

#include <sstream>
#include <string>

#include "third_party/absl/strings/numbers.h"
#include "third_party/absl/strings/string_view.h"

namespace absl {

inline std::string StrCat(int v) {
  std::ostringstream os;
  os << v;
  return os.str();
}

inline std::string StrCat(absl::string_view str) {
  return std::string(str.data(), str.size());
}

template <typename... T>
inline std::string StrCat(absl::string_view first, const T &...rest) {
  return StrCat(first) + StrCat(rest...);
}

template <typename... T>
inline std::string StrCat(int first, const T &...rest) {
  return StrCat(first) + StrCat(rest...);
}

inline void StrAppend(std::string *base, absl::string_view str) {
  base->append(str.data(), str.size());
}

}  // namespace absl
#endif  // ABSL_STRINGS_STR_CAT_H_
