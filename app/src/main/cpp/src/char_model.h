
#ifndef CHAR_MODEL_H_
#define CHAR_MODEL_H_

#include "model_interface.h"
#include "sentencepiece_model.pb.h"

namespace sentencepiece {
namespace character {

// Tokenize text into character sequence
class Model : public ModelInterface {
 public:
  explicit Model(const ModelProto &model_proto);
  ~Model() override;

  EncodeResult Encode(absl::string_view normalized) const override;
};
}  // namespace character
}  // namespace sentencepiece
#endif  // CHAR_MODEL_H_
