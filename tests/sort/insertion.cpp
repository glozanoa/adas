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


// COMPARISON FUNCTION WILL RETURN A BOOL : bool NAME_FUNCTION (ARGS_FUNCTION)
bool lower_than(int x, int y)
{
  return x<y;
}

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


  // CREATE A COPY OF numbers TO TEST insertion WITH CUSTOM COMPARISON
  vector<int> copy_numbers = vector<int>(numbers.size());
  copy(numbers.begin(), numbers.end(), copy_numbers.begin());

  cout << "insertion algorithm (default comparison)" << endl;
  time.start();
  // first booleam enable verbose, the second enable timer
  sort::insertion(numbers.begin(), numbers.end(), true, true);
  time.stop();
  time.report("Elapsed time (sort - default comparison)");

  cout << "insertion algorithm (custom comparison)" << endl;
  time.start();
  sort::insertion(copy_numbers.begin(), copy_numbers.end(), lower_than, true, true);
  time.stop();
  time.report("Elapsed time (sort - custom comparison)");


  fn.close();

  return 0;
}
