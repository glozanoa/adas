/*
 * Test of bubble parallel (multi thread) algorithm
 *
 * DEBUG EXECUTION WITH MORE THAN 2 THREADS (EXIT WITH ERROR) - SOLVED (improve multi_merge function)
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "../../include/io.hpp"
#include "../../include/timer.hpp"
#include "../../include/print.hpp"


#include "../../include/sort.hpp"
namespace sp = sort::parallel;
namespace ss = sort::serial;

int main()
{
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  bool verbose = false;
  unsigned int nthreads = 3;
  Timer time;

  time.start();
  sp::bubble(numbers.begin(), numbers.end(), nthreads, verbose);
  time.stop();
  time.report("Elapsed time (parallel bubble):");

  print::to_stdout("Sorted vector:", numbers); // ONLY FOR DEBUGING PURPOSES
  //write::to_file(sorted.begin(), sorted.end(), "tests/data/sorted_bubble.txt");

  return 0;
}
