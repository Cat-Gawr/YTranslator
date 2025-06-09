
#include "builder.h"
#include "common.h"
#include "filesystem.h"
#include "init.h"
#include "normalizer.h"
#include "sentencepiece.pb.h"
#include "sentencepiece_model.pb.h"
#include "sentencepiece_processor.h"
#include "sentencepiece_trainer.h"
#include "third_party/absl/flags/flag.h"

ABSL_FLAG(std::string, model, "", "Model file name");
ABSL_FLAG(bool, use_internal_normalization, false,
          "Use NormalizerSpec \"as-is\" to run the normalizer "
          "for SentencePiece segmentation");
ABSL_FLAG(std::string, normalization_rule_name, "",
          "Normalization rule name. "
          "Choose from nfkc or identity");
ABSL_FLAG(std::string, normalization_rule_tsv, "",
          "Normalization rule TSV file. ");
ABSL_FLAG(bool, remove_extra_whitespaces, true, "Remove extra whitespaces");
ABSL_FLAG(bool, decompile, false,
          "Decompile compiled charamap and output it as TSV.");
ABSL_FLAG(std::string, input, "", "Input filename");
ABSL_FLAG(std::string, output, "", "Output filename");

using sentencepiece::ModelProto;
using sentencepiece::NormalizerSpec;
using sentencepiece::SentencePieceProcessor;
using sentencepiece::SentencePieceTrainer;
using sentencepiece::normalizer::Builder;
using sentencepiece::normalizer::Normalizer;

int main(int argc, char *argv[]) {
  sentencepiece::ScopedResourceDestructor cleaner;
  sentencepiece::ParseCommandLineFlags(argv[0], &argc, &argv, true);
  std::vector<std::string> rest_args;

  if (absl::GetFlag(FLAGS_input).empty()) {
    for (int i = 1; i < argc; ++i) {
      rest_args.push_back(std::string(argv[i]));
    }
  } else {
    rest_args.push_back(absl::GetFlag(FLAGS_input));
  }

  NormalizerSpec spec;

  if (!absl::GetFlag(FLAGS_model).empty()) {
    ModelProto model_proto;
    SentencePieceProcessor sp;
    CHECK_OK(sp.Load(absl::GetFlag(FLAGS_model)));
    spec = sp.model_proto().normalizer_spec();
  } else if (!absl::GetFlag(FLAGS_normalization_rule_tsv).empty()) {
    spec.set_normalization_rule_tsv(
        absl::GetFlag(FLAGS_normalization_rule_tsv));
    CHECK_OK(SentencePieceTrainer::PopulateNormalizerSpec(&spec));
  } else if (!absl::GetFlag(FLAGS_normalization_rule_name).empty()) {
    spec.set_name(absl::GetFlag(FLAGS_normalization_rule_name));
    CHECK_OK(SentencePieceTrainer::PopulateNormalizerSpec(&spec));
  } else {
    LOG(FATAL) << "Sets --model, normalization_rule_tsv, or "
                  "normalization_rule_name flag.";
  }

  // Uses the normalizer spec encoded in the model_pb.
  if (!absl::GetFlag(FLAGS_use_internal_normalization)) {
    spec.set_add_dummy_prefix(false);    // do not add dummy prefix.
    spec.set_escape_whitespaces(false);  // do not output meta symbol.
    spec.set_remove_extra_whitespaces(
        absl::GetFlag(FLAGS_remove_extra_whitespaces));
  }

  if (absl::GetFlag(FLAGS_decompile)) {
    Builder::CharsMap chars_map;
    CHECK_OK(
        Builder::DecompileCharsMap(spec.precompiled_charsmap(), &chars_map));
    CHECK_OK(Builder::SaveCharsMap(absl::GetFlag(FLAGS_output), chars_map));
  } else {
    const Normalizer normalizer(spec);
    auto output =
        sentencepiece::filesystem::NewWritableFile(absl::GetFlag(FLAGS_output));
    CHECK_OK(output->status());

    if (rest_args.empty()) {
      rest_args.push_back("");  // empty means that read from stdin.
    }

    std::string line;
    for (const auto &filename : rest_args) {
      auto input = sentencepiece::filesystem::NewReadableFile(filename);
      CHECK_OK(input->status());
      while (input->ReadLine(&line)) {
        output->WriteLine(normalizer.Normalize(line));
      }
    }
  }

  return 0;
}
