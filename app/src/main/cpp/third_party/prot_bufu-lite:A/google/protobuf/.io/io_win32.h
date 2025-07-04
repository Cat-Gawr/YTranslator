
#ifndef GOOGLE_PROTOBUF_IO_IO_WIN32_H__
#define GOOGLE_PROTOBUF_IO_IO_WIN32_H__

#if defined(_WIN32)

#include <functional>
#include <string>

#include <google/protobuf/port.h>
#include <google/protobuf/port_def.inc>

// Compilers on Windows other than MSVC (e.g. Cygwin, MinGW32) define the
// following functions already, except for mkdir.
namespace google {
namespace protobuf {
namespace io {
namespace win32 {

PROTOBUF_EXPORT FILE* fopen(const char* path, const char* mode);
PROTOBUF_EXPORT int access(const char* path, int mode);
PROTOBUF_EXPORT int chdir(const char* path);
PROTOBUF_EXPORT int close(int fd);
PROTOBUF_EXPORT int dup(int fd);
PROTOBUF_EXPORT int dup2(int fd1, int fd2);
PROTOBUF_EXPORT int mkdir(const char* path, int _mode);
PROTOBUF_EXPORT int open(const char* path, int flags, int mode = 0);
PROTOBUF_EXPORT int read(int fd, void* buffer, size_t size);
PROTOBUF_EXPORT int setmode(int fd, int mode);
PROTOBUF_EXPORT int stat(const char* path, struct _stat* buffer);
PROTOBUF_EXPORT int write(int fd, const void* buffer, size_t size);
PROTOBUF_EXPORT std::wstring testonly_utf8_to_winpath(const char* path);

enum class ExpandWildcardsResult {
  kSuccess = 0,
  kErrorNoMatchingFile = 1,
  kErrorInputPathConversion = 2,
  kErrorOutputPathConversion = 3,
};

// Expand wildcards in a path pattern, feed the result to a consumer function.
//
// `path` must be a valid, Windows-style path. It may be absolute, or relative
// to the current working directory, and it may contain wildcards ("*" and "?")
// in the last path segment. This function passes all matching file names to
// `consume`. The resulting paths may not be absolute nor normalized.
//
// The function returns a value from `ExpandWildcardsResult`.
PROTOBUF_EXPORT ExpandWildcardsResult ExpandWildcards(
    const std::string& path, std::function<void(const std::string&)> consume);

namespace strings {

// Convert from UTF-16 to Active-Code-Page-encoded or to UTF-8-encoded text.
PROTOBUF_EXPORT bool wcs_to_mbs(const wchar_t* s, std::string* out,
                                bool outUtf8);

// Convert from Active-Code-Page-encoded or UTF-8-encoded text to UTF-16.
PROTOBUF_EXPORT bool mbs_to_wcs(const char* s, std::wstring* out, bool inUtf8);

// Convert from UTF-8-encoded text to UTF-16.
PROTOBUF_EXPORT bool utf8_to_wcs(const char* input, std::wstring* out);

// Convert from UTF-16-encoded text to UTF-8.
PROTOBUF_EXPORT bool wcs_to_utf8(const wchar_t* input, std::string* out);

}  // namespace strings

}  // namespace win32
}  // namespace io
}  // namespace protobuf
}  // namespace google

#ifndef W_OK
#define W_OK 02  // not defined by MSVC for whatever reason
#endif

#ifndef F_OK
#define F_OK 00  // not defined by MSVC for whatever reason
#endif

#ifndef STDIN_FILENO
#define STDIN_FILENO 0
#endif

#ifndef STDOUT_FILENO
#define STDOUT_FILENO 1
#endif

#include <google/protobuf/port_undef.inc>

#endif  // defined(_WIN32)

#endif  // GOOGLE_PROTOBUF_IO_IO_WIN32_H__
