//
#ifndef ABSL_STRINGS_STR_REPLACE_H_
#define ABSL_STRINGS_STR_REPLACE_H_

#include <string>

#include "third_party/absl/strings/string_view.h"

namespace absl {

inline void StringReplace(absl::string_view s, absl::string_view oldsub,
                          absl::string_view newsub, bool replace_all,
                          std::string *res) {
  if (oldsub.empty()) {
    res->append(s.data(), s.size());
    return;
  }

  absl::string_view::size_type start_pos = 0;
  do {
    const absl::string_view::size_type pos = s.find(oldsub, start_pos);
    if (pos == absl::string_view::npos) {
      break;
    }
    res->append(s.data() + start_pos, pos - start_pos);
    res->append(newsub.data(), newsub.size());
    start_pos = pos + oldsub.size();
  } while (replace_all);
  res->append(s.data() + start_pos, s.size() - start_pos);
}

inline std::string StringReplace(absl::string_view s, absl::string_view oldsub,
                                 absl::string_view newsub, bool replace_all) {
  std::string ret;
  StringReplace(s, oldsub, newsub, replace_all, &ret);
  return ret;
}

inline std::string StrReplaceAll(
    absl::string_view s,
    const std::vector<std::pair<absl::string_view, absl::string_view>>
        &patterns) {
  std::string prev(s.data(), s.size());
  std::string result;
  for (const auto &it : patterns) {
    result.clear();
    StringReplace(prev, it.first, it.second, true, &result);
    prev = result;
  }
  return result;
}

}  // namespace absl
#endif  // ABSL_STRINGS_STR_REPLACE_H_
