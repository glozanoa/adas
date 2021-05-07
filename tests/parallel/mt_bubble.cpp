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
  vector<int> numbers = read::from_file<int>("tests/data/unsorted_bubble.txt");
  vector<int> sorted = vector<int>(numbers.size());
  bool verbose = false;

  vector<int> cnumbers = vector<int>(numbers.size()); // vector to test serial bubble algorithm efficiency
  copy(numbers.begin(), numbers.end(), cnumbers.begin());


  Timer time;

  time.start();
  ss::bubble(cnumbers.begin(), cnumbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (serial bubble):");


  time.start();
  sp::bubble(numbers.begin(), numbers.end(), verbose, sorted.begin(), sorted.end());
  time.stop();
  time.report("Elapsed time (parallel bubble):");

  //print::to_stdout("Sorted vector:", sorted);
  write::to_file(sorted.begin(), sorted.end(), "tests/data/sorted_bubble.txt");

  return 0;
}
