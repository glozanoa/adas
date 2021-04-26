/*
 * Testing merge algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/sort.hpp"

int main()
{

  //sels: sorted elements
  vector<int> sels1 = {6, 23, 24};
  vector<int> sels2 = {5, 22, 26, 27, 39};
  bool verbose = true;
  bool timer = true;
  //vector<int> result = vector<int>(sels1.size()+sels2.size());
  int result[7];

  sort::merge(sels1.begin(), sels1.end(),
              sels2.begin(), sels2.end(),
              result);

  print::to_stdout(result, result+8);

  return 0;
}
