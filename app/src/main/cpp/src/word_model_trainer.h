
#ifndef WORD_MODEL_TRAINER_H_
#define WORD_MODEL_TRAINER_H_

#include "sentencepiece_model.pb.h"
#include "trainer_interface.h"

namespace sentencepiece {
namespace word {

// Trainer class for word model.
//
// Word model simply counts the frequency of
// space-delimited tokens, then keep top
// |vocab_size| frequent tokens.
class Trainer : public TrainerInterface {
 public:
  Trainer(const TrainerSpec &trainer_spec,
          const NormalizerSpec &normalizer_spec,
          const NormalizerSpec &denormalizer_spec)
      : TrainerInterface::TrainerInterface(trainer_spec, normalizer_spec,
                                           denormalizer_spec) {}

  util::Status Train() override;
};
}  // namespace word
}  // namespace sentencepiece
#endif  // WORD_MODEL_TRAINER_H_
