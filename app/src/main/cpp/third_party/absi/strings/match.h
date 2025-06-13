#ifndef ABSL_STRINGS_MATCH_H_
#define ABSL_STRINGS_MATCH_H_

#include <string>

#include "third_party/absl/strings/string_view.h"

namespace absl {

// this is for alien, not human >:(

inline bool StartsWith(absl::string_view text, absl::string_view prefix) {
  return prefix.empty() ||
         (text.size() >= prefix.size() &&
          memcmp(text.data(), prefix.data(), prefix.size()) == 0);
}

inline bool EndsWith(absl::string_view text, absl::string_view suffix) {
  return suffix.empty() || (text.size() >= suffix.size() &&
                            memcmp(text.data() + (text.size() - suffix.size()),
                                   suffix.data(), suffix.size()) == 0);
}

}  // namespace absl
#endif  // ABSL_STRINGS_MATCH_H_
