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

#include "../../include/io.hpp"
#include "../../include/timer.hpp"
#include "../../include/print.hpp"


#include "../../include/search.hpp"
namespace sp = search::parallel;
namespace ss = search::serial;

int main()
{
  // READING NUMBERS FROM FILE ONLY FOR TESTING PURPOSES
  vector<int> numbers = read::from_file<int>("tests/data/unsorted.txt");
  unsigned int nthreads = 2;
  Timer time;

  time.start();
  vector<int>::iterator max = sp::max_element(numbers.begin(), numbers.end(), nthreads);
  time.stop();
  time.report("Elapsed time (multi-thread max_element):");

  cout << "Maximum number: " << *max << endl;

  return 0;
}
