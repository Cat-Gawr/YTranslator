#include "pretokenizer_for_training.h"

#include <string>

#include "third_party/absl/strings/str_replace.h"

namespace sentencepiece {
namespace pretokenizer {

namespace {
// TODO(taku): They are defined in trainer_interface.h but we
// defined them explicitly to avoid the dependency to trainier_interface.
// Currently, we have no separated build rules.
const char kWSStr[] = "\xe2\x96\x81";
}  // namespace

std::vector<std::string> PretokenizerForTrainingInterface::PreTokenize(
    absl::string_view text) const {
  return Postprocess(Tokenize(Preprocess(text)));
}

// static
std::string PretokenizerForTrainingInterface::Preprocess(
    absl::string_view text) {
  // Escapes kWSStr (_) as this character may not be processed by pre-tokenizer.
  return absl::StrReplaceAll(text, {{kWSStr, " "}});
}

// static
std::vector<std::string> PretokenizerForTrainingInterface::Postprocess(
    const SentencePieceText &spt) {
  // Inserts kUPPBoundaryStr before/after of token boundaries.
  std::vector<std::string> result;
  std::string output;

  int prev = 0;
  for (const auto &piece : spt.pieces()) {
    if (prev == piece.begin() && piece.begin() != 0) {
      result.push_back(output);
      output.clear();
    } else {
      output.append(piece.begin() - prev, ' ');
    }
    output += piece.surface();
    prev = piece.end();
  }

  if (!output.empty()) result.push_back(output);

  for (auto &w : result) w = absl::StrReplaceAll(w, {{" ", kWSStr}});

  return result;
}

}  // namespace pretokenizer
}  // namespace sentencepiece
