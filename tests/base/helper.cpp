/*
 * Test of function in helper.hpp header file
 */

#include <iostream>
#include <string>
using namespace std;

#include "../../include/helper.hpp"
#include "../../include/print.hpp"

int main()
{
  string simple = "hi";
  string compound = repeat(simple, 3);

  cout << "3*" << simple  << " : " << compound << endl;

  vector<int> numbers = {3, 2, 5, 1, 6};

  vector<int>::iterator min = minimum(numbers.begin(), numbers.end());

  print::to_stdout(numbers);
  cout << "Minimum: " << *min << endl;

  return 0;
}
