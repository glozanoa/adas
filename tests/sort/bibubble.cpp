/*
 * Testing bidirectional bubble sorting algorithm
 *
 * Status: DEBUGGED - date : Mar 7 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "../../include/io.hpp"
#include "../../include/sort.hpp"
namespace ss = sort::serial;

int main()
{

  Timer time;
  bool verbose = true;
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");

  time.start();
  ss::bibubble(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (bibubble sorting algorithm)");

  //write::to_file(numbers.begin(), number.end(), "tests/data/sorted_bibubble.txt")
  print::to_stdout("Sorted:", numbers);
  return 0;
}
