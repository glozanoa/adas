/*
 * Testing binary insertion sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/sort.hpp"

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  bool verbose = true;

  vector<int> sorted_numbers = Sort<int>::binary_insertion(numbers, verbose);

  cout << "(Sorted numbers)" << endl;
  print(sorted_numbers);

  return 0;
}
