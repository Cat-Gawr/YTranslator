
#ifndef MODEL_FACTORY_H_
#define MODEL_FACTORY_H_

#include <memory>

#include "model_interface.h"
#include "sentencepiece_model.pb.h"

namespace sentencepiece {

class ModelFactory {
 public:
  // Creates Model instance from |model_proto|.
  static std::unique_ptr<ModelInterface> Create(const ModelProto &model_proto);
};
}  // namespace sentencepiece
#endif  // MODEL_FACTORY_H_
