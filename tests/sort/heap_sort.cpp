/*
 * Testing heap sort algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include "../../include/sort.hpp"
#include "../../include/print.hpp"


int main()
{

  vector<int> keys = {7, 2, 10, 8, 16, 9, 3, 14, 4, 1};

  vector<int> sorted_keys = sort::heap_sort(keys);
  print::to_stdout(sorted_keys);

  return 0;
}
