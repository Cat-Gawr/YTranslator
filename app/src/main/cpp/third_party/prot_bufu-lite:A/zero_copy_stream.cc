
#include <google/protobuf/io/zero_copy_stream.h>

#include <google/protobuf/stubs/logging.h>
#include <google/protobuf/stubs/common.h>

namespace google {
namespace protobuf {
namespace io {


bool ZeroCopyOutputStream::WriteAliasedRaw(const void* /* data */,
                                           int /* size */) {
  GOOGLE_LOG(FATAL) << "This ZeroCopyOutputStream doesn't support aliasing. "
                "Reaching here usually means a ZeroCopyOutputStream "
                "implementation bug.";
  return false;
}

}  // namespace io
}  // namespace protobuf
}  // namespace google
