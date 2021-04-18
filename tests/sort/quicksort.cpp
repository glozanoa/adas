/*
 * Testing quicksort sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/sort.hpp"

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  vector<int> pivots = {50, 18, 99};
  bool verbose = true;

  vector<int> sorted_numbers = Sort<int>::quicksort(numbers, pivots, verbose, Sort<int>::bubble);

  cout << "(Sorted numbers)" << endl;
  print(sorted_numbers);

  return 0;
}
