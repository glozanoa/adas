/*
 * Test of heap template class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include "adas/ds/heap.hpp"

int main()
{

  vector<int> keys = {7, 2, 10, 8, 16, 9, 3, 14, 4, 1};

  Heap<int> h = Heap<int>(keys);

  h.build_max_heap(false);

  h.print_keys();

  return 0;
}
