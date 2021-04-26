 /*
 * Testing bubble sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "../../include/sort.hpp"
#include "../../include/helper.hpp"
#include "../../include/print.hpp"
#include "../../include/timer.hpp"

/*  NOTE: Compile with Makefile and run in ROOT DIRECTORY OF REPOSITORY */

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
  sort::bubble(numbers.begin(), numbers.end(), false);
  time.stop();
  time.report("Elapsed time (sort)");

  ofstream sn("tests/data/random.txt.sorted");

  for(int number: numbers)
    sn << number << endl;

  sn.close();
  fn.close();

  return 0;
}
