
#include <unordered_map>

#include "third_party/absl/container/flat_hash_map.h"
#include "unicode_script.h"
#include "unicode_script_map.h"
#include "util.h"

namespace sentencepiece {
namespace unicode_script {
namespace {
class GetScriptInternal {
 public:
  GetScriptInternal() { InitTable(&smap_); }

  ScriptType GetScript(char32 c) const {
    return port::FindWithDefault(smap_, c, ScriptType::U_Common);
  }

 private:
  absl::flat_hash_map<char32, ScriptType> smap_;
};
}  // namespace

ScriptType GetScript(char32 c) {
  static GetScriptInternal sc;
  return sc.GetScript(c);
}
}  // namespace unicode_script
}  // namespace sentencepiece
