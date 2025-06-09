#include "filesystem.h"

#include <fstream>
#include <iostream>
#include <memory>

#include "util.h"

#if defined(OS_WIN) && defined(UNICODE) && defined(_UNICODE)
#define WPATH(path) (::sentencepiece::util::Utf8ToWide(path).c_str())
#else
#define WPATH(path) (path.data())
#endif

namespace sentencepiece {
namespace filesystem {

class PosixReadableFile : public ReadableFile {
 public:
  PosixReadableFile(absl::string_view filename, bool is_binary = false)
      : is_(filename.empty()
                ? &std::cin
                : new std::ifstream(WPATH(filename),
                                    is_binary ? std::ios::binary | std::ios::in
                                              : std::ios::in)) {
    if (!*is_)
      status_ = util::StatusBuilder(util::StatusCode::kNotFound, GTL_LOC)
                << "\"" << filename.data() << "\": " << util::StrError(errno);
  }

  ~PosixReadableFile() {
    if (is_ != &std::cin) delete is_;
  }

  util::Status status() const { return status_; }

  bool ReadLine(std::string *line) {
    return static_cast<bool>(std::getline(*is_, *line));
  }

  bool ReadAll(std::string *line) {
    if (is_ == &std::cin) {
      LOG(ERROR) << "ReadAll is not supported for stdin.";
      return false;
    }
    line->assign(std::istreambuf_iterator<char>(*is_),
                 std::istreambuf_iterator<char>());
    return true;
  }

 private:
  util::Status status_;
  std::istream *is_;
};

class PosixWritableFile : public WritableFile {
 public:
  PosixWritableFile(absl::string_view filename, bool is_binary = false)
      : os_(filename.empty()
                ? &std::cout
                : new std::ofstream(WPATH(filename),
                                    is_binary ? std::ios::binary | std::ios::out
                                              : std::ios::out)) {
    if (!*os_)
      status_ =
          util::StatusBuilder(util::StatusCode::kPermissionDenied, GTL_LOC)
          << "\"" << filename.data() << "\": " << util::StrError(errno);
  }

  ~PosixWritableFile() {
    if (os_ != &std::cout) delete os_;
  }

  util::Status status() const { return status_; }

  bool Write(absl::string_view text) {
    os_->write(text.data(), text.size());
    return os_->good();
  }

  bool WriteLine(absl::string_view text) { return Write(text) && Write("\n"); }

 private:
  util::Status status_;
  std::ostream *os_;
};

using DefaultReadableFile = PosixReadableFile;
using DefaultWritableFile = PosixWritableFile;

std::unique_ptr<ReadableFile> NewReadableFile(absl::string_view filename,
                                              bool is_binary) {
  return std::make_unique<DefaultReadableFile>(filename, is_binary);
}

std::unique_ptr<WritableFile> NewWritableFile(absl::string_view filename,
                                              bool is_binary) {
  return std::make_unique<DefaultWritableFile>(filename, is_binary);
}

}  // namespace filesystem
}  // namespace sentencepiece
