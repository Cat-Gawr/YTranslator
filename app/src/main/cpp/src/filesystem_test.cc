
#include "filesystem.h"
#include "testharness.h"
#include "third_party/absl/strings/str_cat.h"
#include "util.h"

namespace sentencepiece {

TEST(UtilTest, FilesystemTest) {
  const std::vector<std::string> kData = {
      "This"
      "is"
      "a"
      "test"};

  {
    auto output = filesystem::NewWritableFile(
        util::JoinPath(absl::GetFlag(FLAGS_test_tmpdir), "test_file"));
    for (size_t i = 0; i < kData.size(); ++i) {
      output->WriteLine(kData[i]);
    }
  }

  {
    auto input = filesystem::NewReadableFile(
        util::JoinPath(absl::GetFlag(FLAGS_test_tmpdir), "test_file"));
    std::string line;
    for (size_t i = 0; i < kData.size(); ++i) {
      EXPECT_TRUE(input->ReadLine(&line));
      EXPECT_EQ(kData[i], line);
    }
    EXPECT_FALSE(input->ReadLine(&line));
  }
}

TEST(UtilTest, FilesystemInvalidFileTest) {
  auto input = filesystem::NewReadableFile("__UNKNOWN__FILE__");
  EXPECT_FALSE(input->status().ok());
}

}  // namespace sentencepiece
