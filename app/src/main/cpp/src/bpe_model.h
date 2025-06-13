
#ifndef BPE_MODEL_H_
#define BPE_MODEL_H_

#include "model_interface.h"
#include "sentencepiece_model.pb.h"

namespace sentencepiece {
namespace bpe {

// Segmentation model with BPE (Byte Pair Encoding)
// Details:
// Neural Machine Translation of Rare Words with Subword Units
// https://arxiv.org/abs/1508.07909
//
// https://en.wikipedia.org/wiki/Byte_pair_encoding
class Model : public ModelInterface {
 public:
  explicit Model(const ModelProto &model_proto);
  ~Model() override;

  EncodeResult Encode(absl::string_view normalized) const override {
    return SampleEncode(normalized, 0.0);
  }

  // Sampling with BPE-dropout: https://arxiv.org/pdf/1910.13267.pdf
  // `alpha` is dropout probability in BPE-dropout paper.
  // Skips merge operation with `alpha` probability.
  // When alpha <= 0.0, no sampling is performed.
  EncodeResult SampleEncode(absl::string_view normalized,
                            float alpha) const override;

  bool IsSampleEncodeAvailable() const override { return true; }

  bool IsNBestEncodeAvailable() const override { return false; }
};
}  // namespace bpe
}  // namespace sentencepiece
#endif  // BPE_MODEL_H_
