/*
 * Testing bidirectional bubble sorting algorithm
 *
 * Updated - date: May 4 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "../../include/sort.hpp"
#include "../../include/io.hpp"

int main()
{

  Timer time;
  bool verbose = true;
  vector<int> numbers = read::from_file("tests/data/unsorted.txt");

  time.start();
  sort::bibubble(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (bibubble sorting algorithm)");

  write::to_file(numbers.begin(), number.end(), "tests/data/sorted_bibubble.txt")
  return 0;
}
