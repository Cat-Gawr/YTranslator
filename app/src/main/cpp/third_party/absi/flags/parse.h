
#ifndef ABSL_FLAGS_PARSE_H_
#define ABSL_FLAGS_PARSE_H_

#include <vector>

namespace absl {

std::vector<char *> ParseCommandLine(int argc, char *argv[]);
}  // namespace absl

#endif  // ABSL_FLAGS_PARSE_H_
