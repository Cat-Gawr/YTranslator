
#ifndef PRETOKENIZER_FOR_TRAINING_H_
#define PRETOKENIZER_FOR_TRAINING_H_

#include <memory>
#include <string>

#include "common.h"
#include "sentencepiece.pb.h"
#include "sentencepiece_processor.h"
#include "third_party/absl/strings/string_view.h"

namespace sentencepiece {
namespace pretokenizer {

class PretokenizerForTrainingInterface {
 public:
  PretokenizerForTrainingInterface() {}
  virtual ~PretokenizerForTrainingInterface() {}
  virtual util::Status status() const = 0;

  // Puts kUPPBoundaryStr before and after the pre-tokenizer's segmentation
  // when there are no spaces between these tokens.
  // Example1:
  // input: 東京です
  // segmentation: piece[0] = {0, 6}, piece[1] = {6, 12}
  // output: 東京<tab>です (here kUPPBoundaryStr is <tab>)
  //
  // Example2:
  // input: I love sentencepiece
  // segmentation: piece[0] = {0, 1}, piece[1] = {2, 6},
  //               piece[2] = {7, 15}, piece[3] = {15, 20}
  // output: I love sentence<tab>piece.
  std::vector<std::string> PreTokenize(absl::string_view text) const;

  // Returns pre-tokenized result.
  // Note that the pre-tokenized constraint is specified with the
  // byte offsets (SentencePiece::begin, SentencePiece::end) over
  // the input text.
  virtual SentencePieceText Tokenize(absl::string_view text) const = 0;

 private:
  static std::string Preprocess(absl::string_view text);
  static std::vector<std::string> Postprocess(const SentencePieceText &spt);
};

}  // namespace pretokenizer
}  // namespace sentencepiece

#endif  // PRETOKENIZER_FOR_TRAINING_H_
