/*
 * Testing selection sorting algorithm
 *
 * Status: DEBUGGED - date : Mar 7 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/utilities.hpp"
#include "adas/algorithm.hpp"
namespace ass = adas::algorithm::sort::serial;

int main()
{

  Timer time;
  // READING NUMBERS FROM FILE ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  bool verbose = true;


  time.start();
  ass::selection(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (selection sort)");

  print::to_stdout("sorted numbers:", numbers);

  return 0;
}
