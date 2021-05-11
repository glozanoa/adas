/*
 * Testing heap sort algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include "adas/algorithm.hpp"
namespace ass = adas::algorithm::sort::serial;

int main()
{

  vector<int> keys = {7, 2, 10, 8, 16, 9, 3, 14, 4, 1};

  vector<int> sorted_keys = ass::heap_sort(keys);
  print::to_stdout(sorted_keys);

  return 0;
}
