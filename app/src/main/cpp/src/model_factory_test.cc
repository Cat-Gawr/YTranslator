#include "model_factory.h"
#include "testharness.h"

namespace sentencepiece {

TEST(ModelFactoryTest, BasicTest) {
  ModelProto model_proto;

  auto *sp1 = model_proto.add_pieces();
  auto *sp2 = model_proto.add_pieces();
  auto *sp3 = model_proto.add_pieces();

  sp1->set_type(ModelProto::SentencePiece::UNKNOWN);
  sp1->set_piece("<unk>");
  sp2->set_type(ModelProto::SentencePiece::CONTROL);
  sp2->set_piece("<s>");
  sp3->set_type(ModelProto::SentencePiece::CONTROL);
  sp3->set_piece("</s>");

  auto *sp4 = model_proto.add_pieces();
  sp4->set_piece("test");
  sp4->set_score(1.0);

  {
    model_proto.mutable_trainer_spec()->set_model_type(TrainerSpec::UNIGRAM);
    auto m = ModelFactory::Create(model_proto);
  }

  {
    model_proto.mutable_trainer_spec()->set_model_type(TrainerSpec::BPE);
    auto m = ModelFactory::Create(model_proto);
  }

  {
    model_proto.mutable_trainer_spec()->set_model_type(TrainerSpec::WORD);
    auto m = ModelFactory::Create(model_proto);
  }

  {
    model_proto.mutable_trainer_spec()->set_model_type(TrainerSpec::CHAR);
    auto m = ModelFactory::Create(model_proto);
  }
}
}  // namespace sentencepiece
