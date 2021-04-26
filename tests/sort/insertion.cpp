/*
 * Testing insertion sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

#include "../../include/sort.hpp"

#include "../../include/print.hpp"

int main()
{

  Timer time;
  time.start();

  ifstream fn("tests/data/random.txt");

  vector<int> numbers;
  int number;
  string line;
  while(getline(fn, line))
    {
      number = str2<int>(line);
      numbers.push_back(number);
    }

  time.stop();
  time.report("Elapsed time (read)");


  //vector<int> numbers = {2, 7, 1, 9};

  time.start();
  sort::insertion(numbers.begin(), numbers.end(), false, true);
  time.stop();
  time.report("Elapsed time (sort)");

  time.start();
  ofstream sn("tests/data/random.txt.selection.sorted");

  for(int number: numbers)
    sn << number << endl;

  time.stop();
  time.report("Elapsed time (write)");

  sn.close();
  fn.close();

  return 0;
}
