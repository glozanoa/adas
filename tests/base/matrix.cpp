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

  vector<int> data = {1, 2, 3, 4, 5, 6};
  Matrix<int> mtx(2, 3, data);

  cout << mtx;

  vector<int> row = mtx.get_row(0);
  cout << "row" << endl;
  print(row);

  vector<int> col = mtx.get_col(0);
  cout << "col" << endl;
  print(col);

  unsigned int i = 1;
  unsigned int j = 1;

  cout << "(i:" << i << ", j:" << j << ")aij = " << mtx(i, j) << endl;

  timer.stop();
  timer.report("Elapsed time");

  return 0;
}
