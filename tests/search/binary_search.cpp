/*
 * Testing binary search algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/search.hpp"
#include "../../include/read.hpp"

int main()
{
  //vector<int> numbers = {1, 4, 7, 8, 3, 9, 17, 10, 11, 100, 200, 300};
  vector<int> numbers = Read<int>::from_file("tests/data/bs.txt");
  int number = 85;

  cout << "Number: " << number << endl;

  vector<int>::iterator it = search::binary_search(numbers.begin(), numbers.end(), number);

  if(it != numbers.end())
    cout << "it: " << *it << endl;
  else
    cout << "Number didn't find" << endl;
  return 0;
}
