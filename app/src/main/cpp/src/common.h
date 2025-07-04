
#ifndef COMMON_H_
#define COMMON_H_

#include <stdint.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "config.h"
#include "third_party/absl/strings/string_view.h"

#if defined(_WIN32) && !defined(__CYGWIN__)
#define OS_WIN
#else
#define OS_UNIX
#endif

#ifdef OS_WIN
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#endif

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t char32;
typedef uint32_t uint32;
typedef uint64_t uint64;

static constexpr uint32 kUnicodeError = 0xFFFD;

template <typename T, size_t N>
char (&ArraySizeHelper(T (&array)[N]))[N];

#ifndef _MSC_VER
template <typename T, size_t N>
char (&ArraySizeHelper(const T (&array)[N]))[N];
#endif  // !_MSC_VER

#define arraysize(array) (sizeof(ArraySizeHelper(array)))

#if defined(_FREEBSD)
#include <sys/endian.h>
#endif
#if !defined(__APPLE__) && !defined(_WIN32) && !defined(_FREEBSD)
#include <endian.h>
#if BYTE_ORDER == __BIG_ENDIAN
#define IS_BIG_ENDIAN
#endif
#endif

namespace sentencepiece {
namespace util {
#ifndef OS_WIN
inline uint32 Swap32(uint32 x) { return __builtin_bswap32(x); }
#endif  // OS_WIN
}  // namespace util

namespace error {

void Abort();
void Exit(int code);
void SetTestCounter(int c);
void ResetTestMode();
bool GetTestCounter();

class Die {
 public:
  explicit Die(bool die) : die_(die) {}
  ~Die() {
    std::cerr << std::endl;
    if (die_) {
      Abort();
    }
  }
  int operator&(std::ostream &) { return 0; }

 private:
  bool die_;
};
}  // namespace error

namespace logging {
enum LogSeverity {
  LOG_INFO = 0,
  LOG_WARNING = 1,
  LOG_ERROR = 2,
  LOG_FATAL = 3,
  LOG_SEVERITY_SIZE = 4,
};

int GetMinLogLevel();
void SetMinLogLevel(int v);

inline const char *BaseName(const char *path) {
#ifdef OS_WIN
  const char *p = strrchr(path, '\\');
#else
  const char *p = strrchr(path, '/');
#endif
  if (p == nullptr) return path;
  return p + 1;
}
}  // namespace logging
}  // namespace sentencepiece

#define LOG(severity)                                                        \
  (::sentencepiece::logging::GetMinLogLevel() >                              \
   ::sentencepiece::logging::LOG_##severity)                                 \
      ? 0                                                                    \
      : ::sentencepiece::error::Die(                                         \
            ::sentencepiece::logging::LOG_##severity >=                      \
            ::sentencepiece::logging::LOG_FATAL) &                           \
            std::cerr << ::sentencepiece::logging::BaseName(__FILE__) << "(" \
                      << __LINE__ << ") "                                    \
                      << "LOG(" << #severity << ") "

#define CHECK(condition)                                                      \
  (condition) ? 0                                                             \
              : ::sentencepiece::error::Die(true) &                           \
                    std::cerr << ::sentencepiece::logging::BaseName(__FILE__) \
                              << "(" << __LINE__ << ") [" << #condition       \
                              << "] "

#define CHECK_STREQ(a, b) CHECK_EQ(std::string(a), std::string(b))
#define CHECK_EQ(a, b) CHECK((a) == (b))
#define CHECK_NE(a, b) CHECK((a) != (b))
#define CHECK_GE(a, b) CHECK((a) >= (b))
#define CHECK_LE(a, b) CHECK((a) <= (b))
#define CHECK_GT(a, b) CHECK((a) > (b))
#define CHECK_LT(a, b) CHECK((a) < (b))

#define FRIEND_TEST(a, b) friend class a##_Test_##b;

#define CHECK_OK(expr)                         \
  do {                                         \
    const auto _status = expr;                 \
    CHECK(_status.ok()) << _status.ToString(); \
  } while (0)

#define CHECK_NOT_OK(expr)                      \
  do {                                          \
    const auto _status = expr;                  \
    CHECK(!_status.ok()) << _status.ToString(); \
  } while (0)

#define RETURN_IF_ERROR(expr)          \
  do {                                 \
    const auto _status = expr;         \
    if (!_status.ok()) return _status; \
  } while (0)

#endif  // COMMON_H_
