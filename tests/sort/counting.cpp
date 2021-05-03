/*
 * Testing counting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <vector>
using namespace std;

#include "../../include/sort.hpp"
#include "../../include/print.hpp"


int main()
{

  vector<int> numbers = {2, 5, 3, 0, 2, 3, 0, 3};

  bool verbose = true;
  vector<int> sorted = sort::counting(numbers.begin(), numbers.end(), verbose);

  print::to_stdout("Sorted numbers:", sorted);

  return 0;
}
