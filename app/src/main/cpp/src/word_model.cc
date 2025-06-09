
#include "util.h"
#include "word_model.h"

namespace sentencepiece {
namespace word {

Model::Model(const ModelProto &model_proto) {
  model_proto_ = &model_proto;
  InitializePieces();
}

Model::~Model() {}

EncodeResult Model::Encode(absl::string_view normalized) const {
  if (!status().ok() || normalized.empty()) {
    return {};
  }

  EncodeResult output;
  for (const auto &w : SplitIntoWords(normalized)) {
    output.emplace_back(w, PieceToId(w));
  }

  return output;
}

}  // namespace word
}  // namespace sentencepiece
