
#include "model_factory.h"

#include "bpe_model.h"
#include "char_model.h"
#include "unigram_model.h"
#include "word_model.h"

namespace sentencepiece {

// Instantiate Model instance from |model_proto|
std::unique_ptr<ModelInterface> ModelFactory::Create(
    const ModelProto& model_proto) {
  const auto& trainer_spec = model_proto.trainer_spec();

  switch (trainer_spec.model_type()) {
    case TrainerSpec::UNIGRAM:
      return std::make_unique<unigram::Model>(model_proto);
      break;
    case TrainerSpec::BPE:
      return std::make_unique<bpe::Model>(model_proto);
      break;
    case TrainerSpec::WORD:
      return std::make_unique<word::Model>(model_proto);
      break;
    case TrainerSpec::CHAR:
      return std::make_unique<character::Model>(model_proto);
      break;
    default:
      LOG(ERROR) << "Unknown model_type: " << trainer_spec.model_type();
      return nullptr;
      break;
  }

  return std::make_unique<unigram::Model>(model_proto);
}
}  // namespace sentencepiece
