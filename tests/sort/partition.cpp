/*
 * Testing bubble sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/partition.hpp"

int main()
{
  vector<int> numbers = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  vector<int> pivots = {50, 18, 99};

  Partition<int> p(pivots, numbers);

  p.show();

  return 0;
}
