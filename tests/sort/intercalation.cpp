/*
 * Testing intercalation sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/sort.hpp"

int main()
{

  vector<int> sels1 = {6, 23, 24};
  vector<int> sels2 = {5, 22, 26, 27, 39};
  bool verbose = true;

  vector<int> total_sels = Sort<int>::intercalation(sels1, sels2, verbose);

  cout << "(Sorted numbers)" << endl;
  print(total_sels);

  return 0;
}
