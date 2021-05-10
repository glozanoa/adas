/*
 * Testing counting algorithm
 *
 * Updated - date : May 4 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <vector>
using namespace std;


#include "../../../include/adas/utilities/print.hpp"
#include "../../../include/adas/utilities/io.hpp"

#include "../../../include/adas/algorithm/sort.hpp"
namespace as = adas::algorithm::sort;

int main()
{
  // READ UNSORTED NUMBERS - ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file("tests/data/unsorted.txt")
  bool verbose = true;

  vector<int> sorted = as::serial::counting(numbers.begin(), numbers.end(), verbose);

  print::to_stdout("Sorted numbers:", sorted);

  return 0;
}
