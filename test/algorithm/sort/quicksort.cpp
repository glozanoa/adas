/*
 * Testing quicksort sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;


#include "adas/utilities.hpp"
#include "adas/ds.hpp"
#include "adas/algorithm.hpp"
namespace asp = adas::algorithm::sort::parallel;

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 37, 18, 99, 8, 45, 28};
  vector<int> pivots = {50, 64};
  bool verbose = true;

  vector<int> sorted_numbers = asp::quicksort(numbers, pivots, verbose);
  print::to_stdout("Sorted numbers:", sorted_numbers);

  return 0;
}
