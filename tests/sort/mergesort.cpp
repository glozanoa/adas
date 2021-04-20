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
  bool timer = true;
  vector<int> total_sels;

  cout << "(NORMAL merge sort)" << endl;
  total_sels = Sort<int>::mergesort(sels1, sels2, verbose, timer);
  print(total_sels);

  cout << "(ITERATOR merge sort)" << endl;
  total_sels = Sort<int>::mergesort_itr(sels1, sels2, verbose, timer);
  print(total_sels);

  return 0;
}
