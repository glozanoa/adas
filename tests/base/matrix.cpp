/*
 * Test of matrix base class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "../../include/matrix.hpp"
#include "../../include/timer.hpp"

int main()
{

  Timer timer;
  timer.start();

  vector<int> data1 = {1, 2, 3, 4, 5, 6};
  Matrix<int> mtx(2, 3, data1);

  vector<int> data2 = {5, 3, 1, 0, 2, 7};
  Matrix<int> other(2, 3, data2);

  cout << "mtx:" << endl;
  cout << mtx << endl;

  cout << "other:" << endl;
  cout << other << endl;

  cout << "mtx + other:" << endl;
  cout << mtx + other << endl;

  cout << "mtx - other:" << endl;
  cout << mtx - other << endl;

  timer.stop();
  timer.default_report();

  return 0;
}
