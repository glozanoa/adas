/*
 * Testing efficiency of multithread algorithms against serial algorithms
 *
 * Task: sort 10000 random integer numbers
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <vector>
using namespace std;

#include "adas/utilities.hpp"
#include "adas/algorithm.hpp"
namespace asp = adas::algorithm::sort::parallel;
namespace ass = adas::algorithm::sort::serial;

int main()
{
  /*
   * Random integer numbers were generated using intgen.py python script
   * python3 dgen/intgen.py -u 1 15000 10000  tests/data/unsorted10000.txt
   *
   * READ UNSORTED NUMBERS - ONLY FOR TESTING PURPOSES
   */

  vector<int> numbers = read::from_file<int>("tests/data/unsorted10000.txt");
  vector<int> cnumbers(numbers.size()); // copy of numbers to test serial algorithm
  copy(numbers.begin(), numbers.end(), cnumbers.begin());
  bool verbose = false;
  Timer time;

  time.start();
  ass::bubble(cnumbers.begin(), cnumbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (serial bubble algorithm)");

  unsigned int nthreads = 8;

  time.start();
  asp::bubble(numbers.begin(), numbers.end(), nthreads, verbose);
  time.stop();
  time.report("Elapsed time (multithread bubble algorithm)");

  // writing sorted numbers by multithread algorithms to check if they are sorted
  write::to_file(numbers.begin(), numbers.end(), "tests/data/sorted10000.txt");
}
