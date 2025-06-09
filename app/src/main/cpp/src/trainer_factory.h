
#ifndef TRAINER_FACTORY_H_
#define TRAINER_FACTORY_H_

#include <memory>

#include "sentencepiece_model.pb.h"
#include "trainer_interface.h"

namespace sentencepiece {

class TrainerFactory {
 public:
  // Creates Trainer instance from |trainer_spec| and |normalizer_spec|.
  static std::unique_ptr<TrainerInterface> Create(
      const TrainerSpec &trainer_spec, const NormalizerSpec &normalizer_spec,
      const NormalizerSpec &denormalizer_spec);
};
}  // namespace sentencepiece
#endif  // TRAINER_FACTORY_H_
