
#include "common.h"
#include "testharness.h"
#include "third_party/absl/strings/string_view.h"
#include "unicode_script.h"
#include "util.h"

namespace sentencepiece {
namespace unicode_script {
ScriptType GetScriptType(absl::string_view s) {
  const auto ut = string_util::UTF8ToUnicodeText(s);
  CHECK_EQ(1, ut.size());
  return GetScript(ut[0]);
}

TEST(UnicodeScript, GetScriptTypeTest) {
  EXPECT_EQ(U_Han, GetScriptType("京"));
  EXPECT_EQ(U_Han, GetScriptType("太"));
  EXPECT_EQ(U_Hiragana, GetScriptType("い"));
  EXPECT_EQ(U_Katakana, GetScriptType("グ"));
  EXPECT_EQ(U_Common, GetScriptType("ー"));
  EXPECT_EQ(U_Latin, GetScriptType("a"));
  EXPECT_EQ(U_Latin, GetScriptType("A"));
  EXPECT_EQ(U_Common, GetScriptType("0"));
  EXPECT_EQ(U_Common, GetScriptType("$"));
  EXPECT_EQ(U_Common, GetScriptType("@"));
  EXPECT_EQ(U_Common, GetScriptType("-"));
}
}  // namespace unicode_script
}  // namespace sentencepiece
