/*
 * Testing insertion sorting algorithm
 *
 * Status: DEBUGGED - date: May 7 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
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
  ass::insertion(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (selection sort)");

  print::to_stdout("Sorted numbers:", numbers);

  return 0;
}
