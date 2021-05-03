/*
 * Testing secuential search algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "../../include/search.hpp"

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  int number = 100;

  bool is_number = search::is_element(numbers.begin(), numbers.end(), number);

  if(!is_number)
    cout << number << "doesn't belows to numbers "  << endl;
  else
    cout << number << "belows to numbers " << endl;

  vector<int>::iterator it = search::secuential(numbers.begin(), numbers.end(), number);

  if(it == numbers.end())
    cout << "it is end" << endl;

  // if(it == nullptr)
  //   cout << "it is nullptr" << endl;

  cout << "Number: " << *it << endl;

  return 0;
}
