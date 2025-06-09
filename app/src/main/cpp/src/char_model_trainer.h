
#ifndef CHAR_MODEL_TRAINER_H_
#define CHAR_MODEL_TRAINER_H_

#include "sentencepiece_model.pb.h"
#include "trainer_interface.h"

namespace sentencepiece {
namespace character {

// Trainer class for character model.
class Trainer : public TrainerInterface {
 public:
  Trainer(const TrainerSpec &trainer_spec,
          const NormalizerSpec &normalizer_spec,
          const NormalizerSpec &denormalizer_spec)
      : TrainerInterface::TrainerInterface(trainer_spec, normalizer_spec,
                                           denormalizer_spec) {}

  util::Status Train() override;
};
}  // namespace character
}  // namespace sentencepiece
#endif  // CHAR_MODEL_TRAINER_H_
