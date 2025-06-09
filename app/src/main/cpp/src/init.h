
#ifndef INIT_H_
#define INIT_H_

#include "common.h"
#include "third_party/absl/flags/flag.h"
#include "third_party/absl/flags/parse.h"

#ifdef _USE_EXTERNAL_PROTOBUF
#include "google/protobuf/message_lite.h"
#else
#include "third_party/protobuf-lite/google/protobuf/message_lite.h"
#endif

ABSL_DECLARE_FLAG(int32, minloglevel);

namespace sentencepiece {
inline void ParseCommandLineFlags(const char *usage, int *argc, char ***argv,
                                  bool remove_arg = true) {
  const auto unused_args = absl::ParseCommandLine(*argc, *argv);

  if (remove_arg) {
    char **argv_val = *argv;
    *argv = argv_val = argv_val + *argc - unused_args.size();
    std::copy(unused_args.begin(), unused_args.end(), argv_val);
    *argc = static_cast<int>(unused_args.size());
  }

  logging::SetMinLogLevel(absl::GetFlag(FLAGS_minloglevel));
}

inline void ShutdownLibrary() {
  google::protobuf::ShutdownProtobufLibrary();
#ifdef HAS_ABSL_CLEANUP_FLAGS
  absl::CleanupFlags();
#endif
}

class ScopedResourceDestructor {
 public:
  ScopedResourceDestructor() {}
  ~ScopedResourceDestructor() { ShutdownLibrary(); }
};

}  // namespace sentencepiece

#endif  // INIT_H_
