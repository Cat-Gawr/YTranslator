
#ifndef ABSL_CONTAINER_FLAT_HASH_MAP_
#define ABSL_CONTAINER_FLAT_HASH_MAP_

#include <unordered_map>

namespace absl {

template <typename K, typename V, typename Hash = std::hash<K>,
          typename Eq = std::equal_to<K>,
          typename Allocator = std::allocator<std::pair<const K, V>>>
using flat_hash_map = std::unordered_map<K, V, Hash, Eq, Allocator>;

}

#endif  // ABSL_CONTAINER_FLAT_HASH_MAP_
