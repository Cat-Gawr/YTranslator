
#include "testharness.h"

#ifndef OS_WIN
#include <sys/stat.h>
#include <unistd.h>
#else
#include <direct.h>
#endif

#include <memory>
#include <string>
#include <vector>

#include "common.h"
#include "third_party/absl/strings/str_cat.h"
#include "util.h"

namespace sentencepiece {
namespace test {

namespace {
struct Test {
  const char *base;
  const char *name;
  void (*func)();
};
std::vector<Test> *tests;
}  // namespace

bool RegisterTest(const char *base, const char *name, void (*func)()) {
  if (tests == nullptr) {
    tests = new std::vector<Test>;
  }
  Test t;
  t.base = base;
  t.name = name;
  t.func = func;
  tests->emplace_back(t);
  return true;
}

int RunAllTests() {
  int num = 0;
#ifdef OS_WIN
  _mkdir(absl::GetFlag(FLAGS_test_tmpdir).c_str());
#else
  mkdir(absl::GetFlag(FLAGS_test_tmpdir).c_str(), S_IRUSR | S_IWUSR | S_IXUSR);
#endif

  if (tests == nullptr) {
    std::cerr << "No tests are found" << std::endl;
    return 0;
  }

  for (const Test &t : *(tests)) {
    std::cerr << "[ RUN      ] " << t.base << "." << t.name << std::endl;
    (*t.func)();
    std::cerr << "[       OK ] " << t.base << "." << t.name << std::endl;
    ++num;
  }
  std::cerr << "==== PASSED " << num << " tests" << std::endl;

  return 0;
}
}  // namespace test
}  // namespace sentencepiece
