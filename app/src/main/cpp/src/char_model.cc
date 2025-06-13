
#include "char_model.h"
#include "util.h"

namespace sentencepiece {
namespace character {

Model::Model(const ModelProto &model_proto) {
  model_proto_ = &model_proto;
  InitializePieces();
}

Model::~Model() {}

EncodeResult Model::Encode(absl::string_view normalized) const {
  if (!status().ok() || normalized.empty()) {
    return {};
  }

  // Splits the input into character sequence
  EncodeResult output;
  while (!normalized.empty()) {
    const int mblen = matcher_->PrefixMatch(normalized);
    absl::string_view w(normalized.data(), mblen);
    output.emplace_back(w, PieceToId(w));
    normalized.remove_prefix(mblen);
  }

  return output;
}

}  // namespace character
}  // namespace sentencepiece
