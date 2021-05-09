/*
 * Testing insertion sorting algorithm
 *
 * Status: DEBUGGED - date: May 7 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;



#include "../../../include/adas/utilities/print.hpp"
#include "../../../include/adas/utilities/timer.hpp"
#include "../../../include/adas/utilities/io.hpp"

#include "../../../include/adas/algorithm/sort.hpp"
namespace as = adas::algorithm::sort;

int main()
{
  Timer time;
  // READING NUMBERS FROM FILE ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  bool verbose = true;


  time.start();
  as::serial::insertion(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (selection sort)");

  print::to_stdout("Sorted numbers:", numbers);

  return 0;
}
