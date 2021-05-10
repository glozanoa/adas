/*
 * Testing quicksort sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/partition.hpp"
#include "../../include/sort.hpp"
#include "../../include/print.hpp"


int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 37, 18, 99, 8, 45, 28};
  vector<int> pivots = {50, 64};
  bool verbose = true;

  vector<int> sorted_numbers = sort::quicksort(numbers, pivots, verbose);
  print::to_stdout("Sorted numbers:", sorted_numbers);

  return 0;
}
