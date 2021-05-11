/*
 * Testing merge algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;


#include "adas/utilities.hpp"
#include "adas/algorithm.hpp"
namespace ass = adas::algorithm::sort::serial;

int main()
{

  //sels: sorted elements
  vector<int> sels1 = {6, 23, 24};
  print::to_stdout("sels1:", sels1);

  vector<int> sels2 = {5, 22, 26, 27, 39};
  print::to_stdout("sels2:", sels2);

  vector<int> result = vector<int>(sels1.size()+sels2.size());

  ass::merge(sels1.begin(), sels1.end(),
             sels2.begin(), sels2.end(),
             result.begin());

  print::to_stdout("merged:", result);

  return 0;
}
