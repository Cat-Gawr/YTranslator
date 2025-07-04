#include <google/protobuf/stubs/status.h>

#include <ostream>
#include <stdio.h>
#include <string>
#include <utility>

namespace google {
namespace protobuf {
namespace util {
namespace error {
inline std::string CodeEnumToString(error::Code code) {
  switch (code) {
    case OK:
      return "OK";
    case CANCELLED:
      return "CANCELLED";
    case UNKNOWN:
      return "UNKNOWN";
    case INVALID_ARGUMENT:
      return "INVALID_ARGUMENT";
    case DEADLINE_EXCEEDED:
      return "DEADLINE_EXCEEDED";
    case NOT_FOUND:
      return "NOT_FOUND";
    case ALREADY_EXISTS:
      return "ALREADY_EXISTS";
    case PERMISSION_DENIED:
      return "PERMISSION_DENIED";
    case UNAUTHENTICATED:
      return "UNAUTHENTICATED";
    case RESOURCE_EXHAUSTED:
      return "RESOURCE_EXHAUSTED";
    case FAILED_PRECONDITION:
      return "FAILED_PRECONDITION";
    case ABORTED:
      return "ABORTED";
    case OUT_OF_RANGE:
      return "OUT_OF_RANGE";
    case UNIMPLEMENTED:
      return "UNIMPLEMENTED";
    case INTERNAL:
      return "INTERNAL";
    case UNAVAILABLE:
      return "UNAVAILABLE";
    case DATA_LOSS:
      return "DATA_LOSS";
  }

  // No default clause, clang will abort if a code is missing from
  // above switch.
  return "UNKNOWN";
}
}  // namespace error.

const Status Status::OK = Status();
const Status Status::CANCELLED = Status(error::CANCELLED, "");
const Status Status::UNKNOWN = Status(error::UNKNOWN, "");

Status::Status() : error_code_(error::OK) {
}

Status::Status(error::Code error_code, StringPiece error_message)
    : error_code_(error_code) {
  if (error_code != error::OK) {
    error_message_ = error_message.ToString();
  }
}

Status::Status(const Status& other)
    : error_code_(other.error_code_), error_message_(other.error_message_) {
}

Status& Status::operator=(const Status& other) {
  error_code_ = other.error_code_;
  error_message_ = other.error_message_;
  return *this;
}

bool Status::operator==(const Status& x) const {
  return error_code_ == x.error_code_ &&
      error_message_ == x.error_message_;
}

std::string Status::ToString() const {
  if (error_code_ == error::OK) {
    return "OK";
  } else {
    if (error_message_.empty()) {
      return error::CodeEnumToString(error_code_);
    } else {
      return error::CodeEnumToString(error_code_) + ":" +
          error_message_;
    }
  }
}

std::ostream& operator<<(std::ostream& os, const Status& x) {
  os << x.ToString();
  return os;
}

}  // namespace util
}  // namespace protobuf
}  // namespace google
