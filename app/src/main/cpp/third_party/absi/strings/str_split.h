//
#ifndef ABSL_STRINGS_STR_SPLIT_H_
#define ABSL_STRINGS_STR_SPLIT_H_

#include <string>
#include <vector>

#include "third_party/absl/strings/string_view.h"

namespace absl {
namespace internal {

class Splitter {
 public:
  Splitter(absl::string_view str, absl::string_view delim, bool allow_empty) {
    size_t current_pos = 0;
    size_t found_pos = 0;
    while ((found_pos = str.find_first_of(delim, current_pos)) !=
           absl::string_view::npos) {
      if ((allow_empty && found_pos >= current_pos) ||
          (!allow_empty && found_pos > current_pos)) {
        result_.push_back(str.substr(current_pos, found_pos - current_pos));
      }
      current_pos = found_pos + 1;
    }
    if (str.size() > current_pos) {
      result_.push_back(str.substr(current_pos, str.size() - current_pos));
    }
  }
  template <class T>
  operator std::vector<T>() const;

  using const_iterator = std::vector<absl::string_view>::const_iterator;
  const_iterator begin() const { return result_.begin(); }
  const_iterator end() const { return result_.end(); }

 private:
  std::vector<absl::string_view> result_;
};

template <>
inline Splitter::operator std::vector<std::string>() const {
  std::vector<std::string> x(result_.size());
  for (size_t i = 0; i < x.size(); ++i)
    x[i].assign(result_[i].data(), result_[i].size());
  return x;
}

template <>
inline Splitter::operator std::vector<absl::string_view>() const {
  return result_;
}
}  // namespace internal

inline constexpr bool AllowEmpty() { return true; };

inline internal::Splitter StrSplit(absl::string_view str,
                                   absl::string_view delim,
                                   bool allow_empty = false) {
  return internal::Splitter(str, delim, allow_empty);
}

inline internal::Splitter StrSplit(absl::string_view str, const char c,
                                   bool allow_empty = false) {
  char delim[2];
  delim[0] = c;
  delim[1] = '\0';
  return internal::Splitter(str, delim, allow_empty);
}

}  // namespace absl
#endif  // ABSL_STRINGS_STR_SPLIT_H_
