
#include <google/protobuf/stubs/statusor.h>

#include <google/protobuf/stubs/logging.h>

namespace google {
namespace protobuf {
namespace util {
namespace internal {

void StatusOrHelper::Crash(const Status& status) {
  GOOGLE_LOG(FATAL) << "Attempting to fetch value instead of handling error "
                    << status.ToString();
}

}  // namespace internal
}  // namespace util
}  // namespace protobuf
}  // namespace google
