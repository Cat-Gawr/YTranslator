
#include "init.h"
#include "testharness.h"

#ifdef OS_WIN
ABSL_FLAG(std::string, test_srcdir, "..\\data", "Data directory.");
#else
ABSL_FLAG(std::string, test_srcdir, "../data", "Data directory.");
#endif

ABSL_FLAG(std::string, test_tmpdir, "test_tmp", "Temporary directory.");

int main(int argc, char **argv) {
  sentencepiece::ScopedResourceDestructor cleaner;
  sentencepiece::ParseCommandLineFlags(argv[0], &argc, &argv, true);
  sentencepiece::test::RunAllTests();
  return 0;
}
