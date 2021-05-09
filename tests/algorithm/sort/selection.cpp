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

#include "../../include/print.hpp"
#include "../../include/io.hpp"

#include "../../include/sort.hpp"
namespace ss = sort::serial;

int main()
{

  Timer time;
  // READING NUMBERS FROM FILE ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  bool verbose = true;


  time.start();
  ss::selection(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (selection sort)");

  print::to_stdout("sorted numbers:", numbers);

  return 0;
}
