/*
 * Test of min_element multi-thread algorithm
 *
 * Status: DEBUGGED - date: May 7 2021
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
  vector<int>::iterator min = asp::min_element(numbers.begin(), numbers.end(), nthreads);
  time.stop();
  time.report("Elapsed time (multi-thread min_element):");

  cout << "Minimum number: " << *min << endl;

  return 0;
}
