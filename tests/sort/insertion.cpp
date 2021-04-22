/*
 * Testing insertion sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "../../include/sort.hpp"
//using namespace sort;

#include "../../include/print.hpp"

int main()
{
  vector<int> numbers = {5, 2, 4, 6, 1, 3};
  bool verbose = true;
  bool timer = true;

  sort::insertion(numbers.begin(), numbers.end(), verbose, timer);

  cout << "(Sorted numbers)" << endl;
  print::to_stdout(numbers.begin(), numbers.end());

  return 0;
}
