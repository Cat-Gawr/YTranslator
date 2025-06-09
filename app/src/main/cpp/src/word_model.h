#ifndef WORD_MODEL_H_
#define WORD_MODEL_H_

#include "model_interface.h"
#include "sentencepiece_model.pb.h"

namespace sentencepiece {
namespace word {

// Tokenize text with whitespaces.
class Model : public ModelInterface {
 public:
  explicit Model(const ModelProto &model_proto);
  ~Model() override;

  EncodeResult Encode(absl::string_view normalized) const override;
};
}  // namespace word
}  // namespace sentencepiece
#endif  // WORD_MODEL_H_
