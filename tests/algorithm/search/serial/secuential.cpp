/*
 * Testing secuential search algorithm
 *
 * Status:
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/algorithm/search/serial.hpp"
namespace ass = adas::algorithm::search::serial;

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  int number = 100;

  /* Testing is_element function */

  bool is_number = ass::is_element(numbers.begin(), numbers.end(), number);

  if(!is_number)
    cout << number << " doesn't below to numbers "  << endl;
  else
    cout << number << " belows to numbers " << endl;

  /* Testing secuentia search algorithm */
  vector<int>::iterator it = ass::secuential(numbers.begin(), numbers.end(), number);

  if(it == numbers.end())
    cout << "iterator is end (element didn't find)" << endl;
  else
    cout << "Number: " << *it << endl;

  return 0;
}
