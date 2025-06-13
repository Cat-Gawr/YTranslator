
#include <cmath>

#include "char_model.h"
#include "char_model_trainer.h"
#include "util.h"

namespace sentencepiece {
namespace character {

util::Status Trainer::Train() {
  RETURN_IF_ERROR(status());

  CHECK_OR_RETURN(normalizer_spec_.escape_whitespaces());
  CHECK_EQ_OR_RETURN(TrainerSpec::CHAR, trainer_spec_.model_type());

  RETURN_IF_ERROR(LoadSentences());

  const int vocab_size = trainer_spec_.vocab_size() - meta_pieces_.size();
  CHECK_GE_OR_RETURN(vocab_size, 0);

  uint64 sum = 0;
  for (const auto &it : required_chars_) {
    sum += it.second;
  }

  const auto logsum = std::log(static_cast<float>(sum));

  CHECK_OR_RETURN(final_pieces_.empty());
  for (const auto &it : Sorted(required_chars_)) {
    if (!trainer_spec_.use_all_vocab() &&
        final_pieces_.size() == static_cast<size_t>(vocab_size)) {
      break;
    }
    final_pieces_.emplace_back(
        string_util::UnicodeCharToUTF8(it.first),
        std::log(static_cast<float>(it.second)) - logsum);
  }

  if (trainer_spec_.use_all_vocab()) {
    trainer_spec_.set_vocab_size(final_pieces_.size() + meta_pieces_.size());
  }

  return Save();
}
}  // namespace character
}  // namespace sentencepiece
