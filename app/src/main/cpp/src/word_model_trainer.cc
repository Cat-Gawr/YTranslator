
#include <cmath>
#include <string>

#include "third_party/absl/container/flat_hash_map.h"
#include "third_party/absl/strings/string_view.h"
#include "util.h"
#include "word_model.h"
#include "word_model_trainer.h"

namespace sentencepiece {
namespace word {

util::Status Trainer::Train() {
  RETURN_IF_ERROR(status());

  CHECK_OR_RETURN(normalizer_spec_.escape_whitespaces());
  CHECK_EQ_OR_RETURN(TrainerSpec::WORD, trainer_spec_.model_type());

  RETURN_IF_ERROR(LoadSentences());

  absl::flat_hash_map<std::string, uint64> freq;
  for (const auto &it : sentences_) {
    for (const auto &s : SplitIntoWords(it.first)) {
      freq[std::string(s)] += it.second;
    }
  }

  const int vocab_size = trainer_spec_.vocab_size() - meta_pieces_.size();
  CHECK_GE_OR_RETURN(vocab_size, 0);

  uint64 sum = 0;
  for (const auto &it : freq) {
    sum += it.second;
  }

  const auto logsum = std::log(static_cast<float>(sum));

  CHECK_OR_RETURN(final_pieces_.empty());
  for (const auto &it : Sorted(freq)) {
    if (it.first.find(kUNKStr) != std::string::npos) {
      continue;
    }
    if (!trainer_spec_.use_all_vocab() &&
        final_pieces_.size() == static_cast<size_t>(vocab_size)) {
      break;
    }
    final_pieces_.emplace_back(
        it.first, std::log(static_cast<float>(it.second)) - logsum);
  }

  if (trainer_spec_.use_all_vocab()) {
    trainer_spec_.set_vocab_size(final_pieces_.size() + meta_pieces_.size());
  }

  return Save();
}
}  // namespace word
}  // namespace sentencepiece
