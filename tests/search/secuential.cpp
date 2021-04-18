/*
 * Testing secuential search algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/search.hpp"

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  int number = 37;
  bool verbose = true;

  int index = Search<int>::secuential(numbers, number, verbose);

  cout << "index: " << index << endl;

  return 0;
}
