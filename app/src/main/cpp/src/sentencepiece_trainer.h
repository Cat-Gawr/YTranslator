
#ifndef SENTENCEPIECE_TRAINER_H_
#define SENTENCEPIECE_TRAINER_H_

#include <string>
#include <unordered_map>
#include <vector>

#include "sentencepiece_processor.h"

namespace sentencepiece {

class TrainerSpec;
class NormalizerSpec;
class ModelProto;

namespace pretokenizer {
class PretokenizerForTrainingInterface;
}  // namespace pretokenizer

namespace normalizer {
class Normalizer;
}  // namespace normalizer

// Iterator over the training sentences.
// Training sentences are loaded sequentially as follows:
//
// for (; !it.done(); it.Next()) {
//    const std::string &s = it.value();
// }
// RETURN_IF_ERROR(it.status());
//
class SentenceIterator {
 public:
  virtual ~SentenceIterator() {}
  // Returns true if iteration finishes (including error case).
  // Uses SentenceIterator::status() method to know whether
  // all sentences are loaded successfully.
  virtual bool done() const = 0;
  virtual void Next() = 0;
  virtual const std::string &value() const = 0;
  virtual util::Status status() const = 0;
};

class SentencePieceTrainer {
 public:
  // Trains SentencePiece model with `trainer_spec`.
  // Default `normalizer_spec` is used.
  // When `sentence_iterator` is passed, load sentences from the iterator.
  static util::Status Train(const TrainerSpec &trainer_spec,
                            SentenceIterator *sentence_iterator = nullptr,
                            std::string *serialized_model_proto = nullptr);

  // Trains SentencePiece model with `trainer_spec` and
  // `normalizer_spec`.
  // When `sentence_iterator` is passed, load sentences from the iterator.
  static util::Status Train(const TrainerSpec &trainer_spec,
                            const NormalizerSpec &normalizer_spec,
                            SentenceIterator *sentence_iterator = nullptr,
                            std::string *serialized_model_proto = nullptr);

  // Trains SentencePiece model with `trainer_spec`, `normalizer_spec`
  // and `denormalizer_spec`.
  // When `sentence_iterator` is passed, load sentences from the iterator.
  static util::Status Train(const TrainerSpec &trainer_spec,
                            const NormalizerSpec &normalizer_spec,
                            const NormalizerSpec &denormalizer_spec,
                            SentenceIterator *sentence_iterator = nullptr,
                            std::string *serialized_model_proto = nullptr);
  // Trains SentencePiece model with command-line string in `args`,
  // e.g.,
  // '--input=data --model_prefix=m --vocab_size=8192 model_type=unigram'
  // When `sentence_iterator` is passed, load sentences from the iterator.
  static util::Status Train(absl::string_view args,
                            SentenceIterator *sentence_iterator = nullptr,
                            std::string *serialized_model_proto = nullptr);

  // Trains SentencePiece model with mapin `kwargs`.
  // e.g., {{"input", "data"}, {"model_prefix, "m"}, {"vocab_size", "8192"}...}
  static util::Status Train(
      const std::unordered_map<std::string, std::string> &kwargs,
      SentenceIterator *sentence_iterator = nullptr,
      std::string *serialized_model_proto = nullptr);

  // The same as above, but passes the list of sentences.
  static util::Status Train(absl::string_view args,
                            const std::vector<std::string> &sentences,
                            std::string *serialized_model_proto = nullptr);

  // The same as above, but passes the list of sentences.
  static util::Status Train(
      const std::unordered_map<std::string, std::string> &kwargs,
      const std::vector<std::string> &sentences,
      std::string *serialized_model_proto = nullptr);

  // Handy function to make a normalizer spec from the pre-compiled
  // normalization name. Do not use this method in production as it crashes
  // When `name` is invalid. Useful for unittesting.
  static NormalizerSpec GetNormalizerSpec(absl::string_view name);

  // Populates necessary fields (precompiled_charmap) from
  // `NormalizerSpec::name` or `NormalizerSpec::normalization_rule_tsv`.
  static util::Status PopulateNormalizerSpec(NormalizerSpec *normalizer_spec,
                                             bool is_denormalizer = false);

  // Overrides `trainer_spec`, `normalizer_spec`, `denormalizer_spec` with the
  // std::unordered_map in `kargs`.
  static util::Status MergeSpecsFromArgs(
      const std::unordered_map<std::string, std::string> &kwargs,
      TrainerSpec *trainer_spec, NormalizerSpec *normalizer_spec,
      NormalizerSpec *denormalizer_spec);

  // Overrides `trainer_spec`, `normalizer_spec`, `denormalizer_spec` with the
  // command line flags in `args`.
  static util::Status MergeSpecsFromArgs(absl::string_view args,
                                         TrainerSpec *trainer_spec,
                                         NormalizerSpec *normalizer_spec,
                                         NormalizerSpec *denormalizer_spec);

  // Injects global pre-tokenizer that are applied in training time.
  // Pretokenizer is only used for extracting pieces.
  // TODO(taku): It would be better to inject per `trainer_spec`.
  static util::Status SetPretokenizerForTraining(
      const pretokenizer::PretokenizerForTrainingInterface *pretokenizer);

  // Returns the current pretokenizer. if no pretokenizer is defined, returns
  // nullptr.
  static const pretokenizer::PretokenizerForTrainingInterface *
  GetPretokenizerForTraining();

  // Helper function to set `field_name=value` in `message`.
  // When `field_name` is repeated, multiple values can be passed
  // with comma-separated values. `field_name` must not be a nested message.
  // The body of these functions are automatically generated with
  // data/gen_spec_parser.pl
  static util::Status SetProtoField(absl::string_view name,
                                    absl::string_view value,
                                    TrainerSpec *message);

  static util::Status SetProtoField(absl::string_view name,
                                    absl::string_view value,
                                    NormalizerSpec *message);

  // Populates model type from string representation, e.g., "bpe".
  // Supported model: "unigram", "bpe", "word", "char".
  static util::Status PopulateModelTypeFromString(absl::string_view type,
                                                  TrainerSpec *trainer_spec);

 private:
  SentencePieceTrainer() {}
  ~SentencePieceTrainer() {}
};

class SentencePieceNormalizer {
 public:
  SentencePieceNormalizer();
  virtual ~SentencePieceNormalizer();

  virtual util::Status Load(std::unique_ptr<ModelProto> model_proto);

  virtual util::Status Load(absl::string_view filename);

  virtual util::Status LoadFromSerializedProto(absl::string_view serialized);

  virtual util::Status LoadFromRuleTSV(absl::string_view filename);

  virtual util::Status LoadFromRuleName(absl::string_view name);

  virtual util::Status Normalize(absl::string_view input,
                                 std::string *normalized) const;

  virtual util::Status Normalize(absl::string_view input,
                                 std::string *normalized,
                                 std::vector<size_t> *norm_to_orig) const;

  virtual std::string Normalize(absl::string_view input) const;

  virtual NormalizerSpec *mutable_normalizer_spec() const;

  virtual std::string serialized_model_proto() const;

 private:
  std::unique_ptr<normalizer::Normalizer> normalizer_;
  std::unique_ptr<ModelProto> model_proto_;
};

// Converts the utf8 byte spans into Unicode char span.
void ConvertToUnicodeAlignment(absl::string_view orig, absl::string_view norm,
                               std::vector<size_t> *norm_to_orig);

}  // namespace sentencepiece

#endif  // SENTENCEPIECE_TRAINER_H_
