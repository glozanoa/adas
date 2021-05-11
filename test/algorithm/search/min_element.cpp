/*
 * Testing min_element function of search template
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <vector>
using namespace std;

#include "adas/algorithm.hpp"
namespace ass = adas::algorithm::search::serial;

int main()
{

  vector<int> numbers = {1, 3, 7, 0, 4, 2, 5, -1};

  vector<int>::iterator min = ass::min_element(numbers.begin(), numbers.end());

  cout << "Minimum number: " << *min << endl;

  return 0;
}
