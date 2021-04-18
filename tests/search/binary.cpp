/*
 * Testing binary search algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/search.hpp"

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  sort(numbers.begin(), numbers.end());
  int number = 37;
  bool verbose = true;

  cout << "(Sorted vector)" << endl;
  print(numbers);

  int index = Search<int>::binary(numbers, number, verbose);

  cout << "index: " << index << endl;

  return 0;
}
