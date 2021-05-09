 /*
 * Testing bubble sorting algorithm
 *
 * Status: DEBUGGED - date: May 7 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "../../../include/adas/utilities/print.hpp"
#include "../../../include/adas/utilities/timer.hpp"
#include "../../../include/adas/utilities/io.hpp"

#include "../../../include/adas/algorithm/sort.hpp"
namespace as = adas::algorithm::sort;

int main()
{

  Timer time;
  // READ UNSORTED NUMBERS - ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  bool verbose = true;

  time.start();
  as::serial::bubble(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (bubble sort)");

  //printing sorted numbers
  print::to_stdout("Sorted:", numbers);

  return 0;
}
