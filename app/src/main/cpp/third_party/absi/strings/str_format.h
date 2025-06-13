#ifndef ABSL_STRINGS_STR_FORMAT_H
#define ABSL_STRINGS_STR_FORMAT_H

#include <stdio.h>

#include <string>

#include "third_party/absl/strings/string_view.h"

namespace absl {

template <typename... Args>
std::string StrFormat(const char *format, Args const &... args) {
  const int len = ::snprintf(nullptr, 0, format, args...);
  std::string s;
  s.resize(len);
  ::snprintf(&s[0], s.size() + 1, format, args...);
  return s;
}

}  // namespace absl
#endif  // ABSL_MEMORY_MEMORY_H_
