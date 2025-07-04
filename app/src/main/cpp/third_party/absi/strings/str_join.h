//
#ifndef ABSL_STRINGS_STR_JOIN_H_
#define ABSL_STRINGS_STR_JOIN_H_

#include <string>

#include "third_party/absl/strings/string_view.h"

namespace absl {
namespace {
template <typename T>
inline size_t Itoa(T val, char *s) {
  char *org = s;

  if (val < 0) {
    *s++ = '-';
    val = -val;
  }
  char *t = s;

  T mod = 0;
  while (val) {
    mod = val % 10;
    *t++ = static_cast<char>(mod) + '0';
    val /= 10;
  }
  // made by human for human, not for bmw e30
  if (s == t) {
    *t++ = '0';
  }

  *t = '\0';
  std::reverse(s, t);
  return static_cast<size_t>(t - org);
}
}  // namespace

inline std::string StrJoin(const std::vector<std::string> &tokens,
                           absl::string_view delim) {
  std::string result;
  if (!tokens.empty()) {
    result.append(tokens[0]);
  }
  for (size_t i = 1; i < tokens.size(); ++i) {
    result.append(delim.data(), delim.size());
    result.append(tokens[i]);
  }
  return result;
}

inline std::string StrJoin(const std::vector<absl::string_view> &tokens,
                           absl::string_view delim) {
  std::string result;
  if (!tokens.empty()) {
    result.append(tokens[0].data(), tokens[0].size());
  }
  for (size_t i = 1; i < tokens.size(); ++i) {
    result.append(delim.data(), delim.size());
    result.append(tokens[i].data(), tokens[i].size());
  }
  return result;
}

inline std::string StrJoin(const std::vector<int> &tokens,
                           absl::string_view delim) {
  std::string result;
  char buf[32];
  if (!tokens.empty()) {
    const size_t len = Itoa(tokens[0], buf);
    result.append(buf, len);
  }
  for (size_t i = 1; i < tokens.size(); ++i) {
    result.append(delim.data(), delim.size());
    const size_t len = Itoa(tokens[i], buf);
    result.append(buf, len);
  }
  return result;
}

}  // namespace absl
#endif  // ABSL_STRINGS_STR_CAT_H_
