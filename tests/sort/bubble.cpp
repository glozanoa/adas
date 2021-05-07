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

#include "../../include/print.hpp"
#include "../../include/timer.hpp"
#include "../../include/io.hpp"

#include "../../include/sort.hpp"
namespace ss = sort::serial;

int main()
{

  Timer time;
  // READ UNSORTED NUMBERS - ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  bool verbose = true;

  time.start();
  ss::bubble(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (bubble sort)");

  //printing sorted numbers
  print::to_stdout("Sorted:", numbers);

  return 0;
}
