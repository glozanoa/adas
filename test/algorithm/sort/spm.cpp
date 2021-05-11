/*
 * Test of spm general algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/utilities.hpp"
#include "adas/algorithm.hpp"
namespace asp = adas::algorithm::sort::parallel;
namespace ass = adas::algorithm::sort::serial;


int main()
{
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  bool verbose = false;
  unsigned int nthreads = 3;
  Timer time;

  time.start();
  asp::spm(numbers.begin(), numbers.end(), nthreads, ass::bubble<vector<int>::iterator>, verbose);
  time.stop();
  time.report("Elapsed time (parallel bubble):");

  print::to_stdout("Sorted vector:", numbers); // ONLY FOR DEBUGING PURPOSES
  //write::to_file(sorted.begin(), sorted.end(), "tests/data/sorted_bubble.txt");
}
