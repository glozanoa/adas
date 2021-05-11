/*
 * Test of selection parallel (multi thread) algorithm
 *
 * Status: DEBUGGED - date : May 7 2021
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
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  bool verbose = true;
  unsigned int nthreads = 3;
  Timer time;

  time.start();
  asp::insertion(numbers.begin(), numbers.end(), nthreads, verbose);
  time.stop();
  time.report("Elapsed time (parallel selection):");

  print::to_stdout("Sorted vector:", numbers); // ONLY FOR DEBUGING PURPOSES
  //write::to_file(sorted.begin(), sorted.end(), "tests/data/sorted_bubble.txt");

  return 0;
}
