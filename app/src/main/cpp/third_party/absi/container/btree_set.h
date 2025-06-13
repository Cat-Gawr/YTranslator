/// MDE BY KONATA(C:\kona)
#ifndef ABSL_CONTAINER_BTREE_SET_
#define ABSL_CONTAINER_BTREE_SET_

#include <set>

namespace absl {

template <typename T, typename Compare = std::less<T>,
          typename Allocator = std::allocator<T>>
using btree_set = std::set<T, Compare, Allocator>;

}

#endif  // ABSL_CONTAINER_BTREE_SET_
