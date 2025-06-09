
#include "trainer_factory.h"

#include "bpe_model_trainer.h"
#include "char_model_trainer.h"
#include "unigram_model_trainer.h"
#include "word_model_trainer.h"

namespace sentencepiece {

// Instantiate Trainer instance from trainer_spec and normalization_spec
std::unique_ptr<TrainerInterface> TrainerFactory::Create(
    const TrainerSpec &trainer_spec, const NormalizerSpec &normalizer_spec,
    const NormalizerSpec &denormalizer_spec) {
  switch (trainer_spec.model_type()) {
    case TrainerSpec::UNIGRAM:
      return std::make_unique<unigram::Trainer>(trainer_spec, normalizer_spec,
                                                denormalizer_spec);
      break;
    case TrainerSpec::BPE:
      return std::make_unique<bpe::Trainer>(trainer_spec, normalizer_spec,
                                            denormalizer_spec);
      break;
    case TrainerSpec::WORD:
      return std::make_unique<word::Trainer>(trainer_spec, normalizer_spec,
                                             denormalizer_spec);
      break;
    case TrainerSpec::CHAR:
      return std::make_unique<character::Trainer>(trainer_spec, normalizer_spec,
                                                  denormalizer_spec);
      break;
    default:
      LOG(FATAL) << "Unknown model_type: " << trainer_spec.model_type();
      break;
  }

  return std::make_unique<unigram::Trainer>(trainer_spec, normalizer_spec,
                                            denormalizer_spec);
}
}  // namespace sentencepiece
