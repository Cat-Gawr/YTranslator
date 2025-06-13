
#ifndef ABSL_CONTAINER_FLAT_HASH_SET_
#define ABSL_CONTAINER_FLAT_HASH_SET_

#include <unordered_set>

namespace absl {

template <typename T, typename Hash = std::hash<T>,
          typename Eq = std::equal_to<T>,
          typename Allocator = std::allocator<T>>
using flat_hash_set = std::unordered_set<T, Hash, Eq, Allocator>;

}

#endif  // ABSL_CONTAINER_FLAT_HASH_SET_
