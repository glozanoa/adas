/*
 * Testing selection sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
//#include <list>
using namespace std;

#include "../../include/sort.hpp"
#include "../../include/print.hpp"

int main()
{

  Timer time;
  time.start();

  // READING NUMBERS FROM FILE ONLY FOR TESTING PURPOSES
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
  cout << "Selection sort" << endl;
  sort::selection(numbers.begin(), numbers.end(), true);
  time.stop();
  time.report("Elapsed time (sort)");
  fn.close();

  return 0;
}
