/*
 * Testing counting algorithm
 *
 * Updated - date : May 4 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <vector>
using namespace std;

#include "adas/utilities.hpp"
#include "adas/algorithm.hpp"
namespace ass = adas::algorithm::sort::serial;

int main()
{
  // READ UNSORTED NUMBERS - ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file("tests/data/unsorted.txt")
  bool verbose = true;

  vector<int> sorted = ass::serial::counting(numbers.begin(), numbers.end(), verbose);

  print::to_stdout("Sorted numbers:", sorted);

  return 0;
}
