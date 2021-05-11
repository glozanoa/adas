/*
 * Testing partition template class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;


#include "adas/ds.hpp"

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  vector<int> pivots = {18, 50, 84}; // NOTE: pivots will be sorted
  Partition<int> p(pivots, numbers);

  cout << "Before join" << endl;
  p.show();

  cout << "After join" << endl;
  vector<int> join = p.join();
  print::to_stdout(join);


  return 0;
}
