
#include "util.h"

#include <atomic>
#include <iostream>
#include <memory>

namespace sentencepiece {

namespace {
constexpr unsigned int kDefaultSeed = static_cast<unsigned int>(-1);
static std::atomic<unsigned int> g_seed = kDefaultSeed;
static std::atomic<int> g_minloglevel = 0;
}  // namespace

void SetRandomGeneratorSeed(unsigned int seed) {
  if (seed != kDefaultSeed) g_seed.store(seed);
}

uint32 GetRandomGeneratorSeed() {
  try {
    return g_seed == kDefaultSeed ? std::random_device{}() : g_seed.load();
  } catch (...) {
    return g_seed.load();
  }
}

namespace logging {
int GetMinLogLevel() { return g_minloglevel.load(); }
void SetMinLogLevel(int v) { g_minloglevel.store(v); }
}  // namespace logging

void SetMinLogLevel(int v) { logging::SetMinLogLevel(v); }

namespace string_util {

// mblen sotres the number of bytes consumed after decoding.
char32 DecodeUTF8(const char *begin, const char *end, size_t *mblen) {
  const size_t len = end - begin;

  if (static_cast<unsigned char>(begin[0]) < 0x80) {
    *mblen = 1;
    return static_cast<unsigned char>(begin[0]);
  } else if (len >= 2 && (begin[0] & 0xE0) == 0xC0) {
    const char32 cp = (((begin[0] & 0x1F) << 6) | ((begin[1] & 0x3F)));
    if (IsTrailByte(begin[1]) && cp >= 0x0080 && IsValidCodepoint(cp)) {
      *mblen = 2;
      return cp;
    }
  } else if (len >= 3 && (begin[0] & 0xF0) == 0xE0) {
    const char32 cp = (((begin[0] & 0x0F) << 12) | ((begin[1] & 0x3F) << 6) |
                       ((begin[2] & 0x3F)));
    if (IsTrailByte(begin[1]) && IsTrailByte(begin[2]) && cp >= 0x0800 &&
        IsValidCodepoint(cp)) {
      *mblen = 3;
      return cp;
    }
  } else if (len >= 4 && (begin[0] & 0xf8) == 0xF0) {
    const char32 cp = (((begin[0] & 0x07) << 18) | ((begin[1] & 0x3F) << 12) |
                       ((begin[2] & 0x3F) << 6) | ((begin[3] & 0x3F)));
    if (IsTrailByte(begin[1]) && IsTrailByte(begin[2]) &&
        IsTrailByte(begin[3]) && cp >= 0x10000 && IsValidCodepoint(cp)) {
      *mblen = 4;
      return cp;
    }
  }

  // Invalid UTF-8.
  *mblen = 1;
  return kUnicodeError;
}

bool IsStructurallyValid(absl::string_view str) {
  const char *begin = str.data();
  const char *end = str.data() + str.size();
  size_t mblen = 0;
  while (begin < end) {
    const char32 c = DecodeUTF8(begin, end, &mblen);
    if (c == kUnicodeError && mblen != 3) return false;
    if (!IsValidCodepoint(c)) return false;
    begin += mblen;
  }
  return true;
}

size_t EncodeUTF8(char32 c, char *output) {
  if (c <= 0x7F) {
    *output = static_cast<char>(c);
    return 1;
  }

  if (c <= 0x7FF) {
    output[1] = 0x80 | (c & 0x3F);
    c >>= 6;
    output[0] = 0xC0 | c;
    return 2;
  }

  // if `c` is out-of-range, convert it to REPLACEMENT CHARACTER (U+FFFD).
  // This treatment is the same as the original runetochar.
  if (c > 0x10FFFF) c = kUnicodeError;

  if (c <= 0xFFFF) {
    output[2] = 0x80 | (c & 0x3F);
    c >>= 6;
    output[1] = 0x80 | (c & 0x3F);
    c >>= 6;
    output[0] = 0xE0 | c;
    return 3;
  }

  output[3] = 0x80 | (c & 0x3F);
  c >>= 6;
  output[2] = 0x80 | (c & 0x3F);
  c >>= 6;
  output[1] = 0x80 | (c & 0x3F);
  c >>= 6;
  output[0] = 0xF0 | c;

  return 4;
}

std::string UnicodeCharToUTF8(const char32 c) { return UnicodeTextToUTF8({c}); }

UnicodeText UTF8ToUnicodeText(absl::string_view utf8) {
  UnicodeText uc;
  const char *begin = utf8.data();
  const char *end = utf8.data() + utf8.size();
  while (begin < end) {
    size_t mblen;
    const char32 c = DecodeUTF8(begin, end, &mblen);
    uc.push_back(c);
    begin += mblen;
  }
  return uc;
}

std::string UnicodeTextToUTF8(const UnicodeText &utext) {
  char buf[8];
  std::string result;
  for (const char32 c : utext) {
    const size_t mblen = EncodeUTF8(c, buf);
    result.append(buf, mblen);
  }
  return result;
}
}  // namespace string_util

namespace random {
#ifdef SPM_NO_THREADLOCAL
namespace {
class RandomGeneratorStorage {
 public:
  RandomGeneratorStorage() {
    pthread_key_create(&key_, &RandomGeneratorStorage::Delete);
  }
  virtual ~RandomGeneratorStorage() { pthread_key_delete(key_); }

  std::mt19937 *Get() {
    auto *result = static_cast<std::mt19937 *>(pthread_getspecific(key_));
    if (result == nullptr) {
      result = new std::mt19937(GetRandomGeneratorSeed());
      pthread_setspecific(key_, result);
    }
    return result;
  }

 private:
  static void Delete(void *value) { delete static_cast<std::mt19937 *>(value); }
  pthread_key_t key_;
};
}  // namespace

std::mt19937 *GetRandomGenerator() {
  static RandomGeneratorStorage *storage = new RandomGeneratorStorage;
  return storage->Get();
}
#else
std::mt19937 *GetRandomGenerator() {
  // Thread-locals occupy stack space in every thread ever created by the
  // program, even if that thread never uses the thread-local variable.
  //
  // https://maskray.me/blog/2021-02-14-all-about-thread-local-storage
  //
  // sizeof(std::mt19937) is several kilobytes, so it is safer to put that on
  // the heap, leaving only a pointer to it in thread-local storage.  This must
  // be a unique_ptr, not a raw pointer, so that the generator is not leaked on
  // thread exit.
  thread_local static auto mt =
      std::make_unique<std::mt19937>(GetRandomGeneratorSeed());
  return mt.get();
}
#endif
}  // namespace random

namespace util {

std::string StrError(int errnum) {
  constexpr int kStrErrorSize = 1024;
  char buffer[kStrErrorSize];
  char *str = nullptr;
#if defined(__GLIBC__) && defined(_GNU_SOURCE)
  str = strerror_r(errnum, buffer, kStrErrorSize - 1);
#elif defined(_WIN32)
  strerror_s(buffer, kStrErrorSize - 1, errnum);
  str = buffer;
#else
  strerror_r(errnum, buffer, kStrErrorSize - 1);
  str = buffer;
#endif
  std::ostringstream os;
  os << str << " Error #" << errnum;
  return os.str();
}

std::vector<std::string> StrSplitAsCSV(absl::string_view text) {
  std::string buf = std::string(text);
  char *str = const_cast<char *>(buf.data());
  char *eos = str + text.size();
  char *start = nullptr;
  char *end = nullptr;

  std::vector<std::string> result;
  for (; str < eos; ++str) {
    if (*str == '"') {
      start = ++str;
      end = start;
      for (; str < eos; ++str) {
        if (*str == '"') {
          str++;
          if (*str != '"') break;
        }
        *end++ = *str;
      }
      str = std::find(str, eos, ',');
    } else {
      start = str;
      str = std::find(str, eos, ',');
      end = str;
    }
    *end = '\0';
    result.push_back(start);
  }

  return result;
}

#ifdef OS_WIN
std::wstring Utf8ToWide(absl::string_view input) {
  const int output_length = ::MultiByteToWideChar(
      CP_UTF8, 0, input.data(), static_cast<int>(input.size()), nullptr, 0);
  if (output_length == 0) {
    return L"";
  }
  std::wstring output(output_length, 0);
  const int result = ::MultiByteToWideChar(CP_UTF8, 0, input.data(),
                                           static_cast<int>(input.size()),
                                           output.data(), output.size());
  return result == output_length ? output : L"";
}
#endif
}  // namespace util

namespace log_domain {
double LogSum(const std::vector<double> &xs) {
  if (xs.empty()) {
    return -1.0 * std::numeric_limits<double>::max();
  }
  double sum = xs.front();

  auto log_add = [](double xa, double xb) {
    if (xa > xb) {
      std::swap(xa, xb);
    }
    return xb + std::log1p(std::exp(xa - xb));
  };
  for (int i = 1; i < xs.size(); ++i) {
    sum = log_add(sum, xs[i]);
  }
  return sum;
}
}  // namespace log_domain
}  // namespace sentencepiece
