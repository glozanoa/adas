/*
 * Testing mergesort algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/sort.hpp"
#include "../../include/print.hpp"

int main()
{
  vector<int> numbers = {6, 23, 24, 5, 22, 26, 27, 39};
  bool verbose = true;

  vector<int> aux = vector<int>(numbers.size());

  sort::mergesort(numbers.begin(), numbers.end(),
                  aux.begin(), aux.end(),
                  verbose);

  print::to_stdout("Sorted:", numbers);

  return 0;
}
