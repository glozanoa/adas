/*
 * Test of bubble parallel (multi thread) algorithm
 *
 * DEBUG EXECUTION WITH MORE THAN 2 THREADS (EXIT WITH ERROR) - SOLVED
 * Status - DEBUGGED (RUN SUCEFULLY WITH MORE THAN 2 THREADS) - date: May 7 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/utilities.hpp"
#include "adas/algorithm.hpp"
namespace asp = adas::algorithm::sort::parallel;

int main()
{
  // READING NUMBERS FROM FILE ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  bool verbose = true;
  unsigned int nthreads = 3;
  Timer time;

  time.start();
  asp::bubble(numbers.begin(), numbers.end(), nthreads, verbose);
  time.stop();
  time.report("Elapsed time (parallel bubble):");

  print::to_stdout("Sorted vector:", numbers); // ONLY FOR DEBUGING PURPOSES
  //write::to_file(sorted.begin(), sorted.end(), "tests/data/sorted_bubble.txt");

  return 0;
}
