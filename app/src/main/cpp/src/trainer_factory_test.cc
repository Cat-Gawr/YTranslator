
#include "testharness.h"
#include "trainer_factory.h"

namespace sentencepiece {

TEST(TrainerFactoryTest, BasicTest) {
  TrainerSpec trainer_spec;
  NormalizerSpec normalizer_spec;
  NormalizerSpec denormalizer_spec;

  trainer_spec.set_model_prefix("model");
  trainer_spec.add_input("input");

  {
    trainer_spec.set_model_type(TrainerSpec::UNIGRAM);
    auto m = TrainerFactory::Create(trainer_spec, normalizer_spec,
                                    denormalizer_spec);
  }

  {
    trainer_spec.set_model_type(TrainerSpec::BPE);
    auto m = TrainerFactory::Create(trainer_spec, normalizer_spec,
                                    denormalizer_spec);
  }

  {
    trainer_spec.set_model_type(TrainerSpec::WORD);
    auto m = TrainerFactory::Create(trainer_spec, normalizer_spec,
                                    denormalizer_spec);
  }

  {
    trainer_spec.set_model_type(TrainerSpec::CHAR);
    auto m = TrainerFactory::Create(trainer_spec, normalizer_spec,
                                    denormalizer_spec);
  }
}
}  // namespace sentencepiece
