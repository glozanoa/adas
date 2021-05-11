/*
 * Test of max_element multi-thread algorithm
 *
 * Status:
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;


#include "adas/utilities.hpp"
#include "adas/algorithm.hpp"
namespace asp = adas::algorithm::search::parallel;

int main()
{
  // READING NUMBERS FROM FILE ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  unsigned int nthreads = 2;
  Timer time;

  time.start();
  vector<int>::iterator max = asp::max_element(numbers.begin(), numbers.end(), nthreads);
  time.stop();
  time.report("Elapsed time (multi-thread max_element):");

  cout << "Maximum number: " << *max << endl;

  return 0;
}
