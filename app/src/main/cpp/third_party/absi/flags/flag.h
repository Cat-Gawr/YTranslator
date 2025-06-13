
#ifndef ABSL_FLAGS_FLAG_H_
#define ABSL_FLAGS_FLAG_H_

#include <functional>
#include <memory>
#include <string>
#include <vector>

namespace absl {
namespace internal {
struct FlagFunc;

void RegisterFlag(const std::string &name, std::shared_ptr<FlagFunc> func);

}  // namespace internal

template <typename T>
class Flag {
 public:
  Flag(const char *name, const char *type, const char *help,
       const T &defautl_value);
  virtual ~Flag();
  const T &value() const;
  void set_value(const T &value);
  void set_value_as_str(const std::string &value_as_str);

 private:
  T value_;
  std::shared_ptr<internal::FlagFunc> func_;
};

template <typename T>
const T &GetFlag(const Flag<T> &flag) {
  return flag.value();
}

template <typename T, typename V>
void SetFlag(Flag<T> *flag, const V &v) {
  const T value(v);
  flag->set_value(value);
}

#define HAS_ABSL_CLEANUP_FLAGS

void CleanupFlags();

}  // namespace absl

#define ABSL_FLAG(Type, name, defautl_value, help) \
  absl::Flag<Type> FLAGS_##name(#name, #Type, help, defautl_value);

#define ABSL_DECLARE_FLAG(Type, name) extern absl::Flag<Type> FLAGS_##name;

#endif  // ABSL_FLAGS_FLAG_H_
