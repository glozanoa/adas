/*
 * Testing insertion sorting algorithm
 *
 * Updated - date May 4 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/sort.hpp"
#include "../../include/io.hpp"
#include "../../include/print.hpp"

int main()
{
  vector<int> numbers = read::from_file("test/data/unsorted.txt")
  bool verbose = true;

  vector<int> sorted = sort::insertion(numbers, verbose);

  print::to_stdout("Sorted numbers:", sorted_numbers);

  return 0;
}
