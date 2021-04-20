/*
 * Testing shellsort sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/sort.hpp"

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 19, 2};
  int n = numbers.size();
  vector<int> geps = Sort<int>::shell_gep_sequences(n);
  bool verbose = true;

  vector<int> sorted_numbers = Sort<int>::shellsort(numbers, geps, verbose);

  cout << "(Sorted numbers)" << endl;
  print(sorted_numbers);

  return 0;
}
