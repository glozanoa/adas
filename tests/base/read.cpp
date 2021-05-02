/*
 * Read numbers of a file
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <fstream>

#include "../../include/helper.hpp"
#include "../../include/print.hpp"
#include "../../include/timer.hpp"

int main()
{

  Timer time;
  time.start();

  ifstream fn("../data/random.txt");

  vector<int> numbers;
  int number;
  string line;
  while(getline(fn, line))
    {
      number = str2<int>(line);
      numbers.push_back(number);
    }

  print::to_stdout(numbers.begin(), numbers.end());

  time.stop();
  time.report("Elapsed time (read)");

  return 0;
}
