/*
 * Testing counting algorithm
 *
 * Updated - date : May 4 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <vector>
using namespace std;

#include "../../include/sort.hpp"
#include "../../include/io.hpp"
#include "../../include/print.hpp"


int main()
{

  vector<int> numbers = read::from_file("tests/data/unsorted.txt")
  bool verbose = true;

  vector<int> sorted = sort::counting(numbers.begin(), numbers.end(), verbose);

  print::to_stdout("Sorted numbers:", sorted);

  return 0;
}
