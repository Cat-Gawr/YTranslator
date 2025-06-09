
#include "freelist.h"
#include "testharness.h"

namespace sentencepiece {
namespace model {

TEST(FreeListTest, BasicTest) {
  FreeList<int> l(5);
  EXPECT_EQ(0, l.size());

  constexpr size_t kSize = 32;

  for (size_t i = 0; i < kSize; ++i) {
    int *n = l.Allocate();
    EXPECT_EQ(0, *n);
    *n = i;
  }

  FreeList<int> l2(3);  // Test swap()
  l.swap(l2);

  EXPECT_EQ(kSize, l2.size());
  for (size_t i = 0; i < kSize; ++i) {
    EXPECT_EQ(i, *l2[i]);
  }

  l2.Free();
  EXPECT_EQ(0, l2.size());

  // Zero-initialized after `Free`.
  for (size_t i = 0; i < kSize; ++i) {
    int *n = l2.Allocate();
    EXPECT_EQ(0, *n);
  }
}
}  // namespace model
}  // namespace sentencepiece
