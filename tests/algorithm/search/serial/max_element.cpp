/*
 * Testing max_element function of search template
 *
 * State: DEBUGED - date: May 11 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <vector>
using namespace std;

#include "adas/algorithm/search/serial.hpp"
namespace ass = adas::algorithm::search::serial;

int main()
{

  vector<int> numbers = {1, 3, 7, 0, 4, 2, 5, -1};

  vector<int>::iterator max = ass::max_element(numbers.begin(), numbers.end());

  cout << "Maximum number: " << *max << endl;

  return 0;
}
