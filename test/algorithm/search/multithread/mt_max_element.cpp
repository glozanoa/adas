/*
 * Test of max_element multi-thread algorithm
 *
 * Status: DEBUGGED - date: May 11 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;


#include "adas/algorithm/search/multithread.hpp"
namespace asp = adas::algorithm::search::parallel;

int main()
{
  // READING NUMBERS FROM FILE ONLY FOR TESTING PURPOSES
  vector<int> numbers = {1, 3, 7, 0, 4, 2, 5, -1, 4, 2, 100, 101};
  unsigned int nthreads = 3;
  bool verbose = true;
  Timer time;

  time.start();
  vector<int>::iterator max = asp::max_element(numbers.begin(), numbers.end(), nthreads, verbose);
  time.stop();
  time.report("Elapsed time (multi-thread max_element):");

  cout << "Maximum number: " << *max << endl;

  return 0;
}
