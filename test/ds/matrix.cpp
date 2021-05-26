/*
 * Test of matrix template class
 *
 * Status: DEBUGED - date: May 14 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/ds/matrix.hpp"
namespace ads =  adas::ds;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

int main()
{
  vector<int> data1 = {1, 2, 3, 4, 5, 6};
  ads::Matrix<int> mtx = ads::Matrix<int>(2, 3, data1);

  vector<int> data2 = {5, 3, 1, 0, 2, 7};
  ads::Matrix<int> other = ads::Matrix<int>(2, 3, data2);

  // << operator for Matrix<T>
  cout << "mtx:" << endl;
  cout << mtx << endl;

  cout << "other:" << endl;
  cout << other << endl;

  // operation with matrix rows and columns
  vector<int> row0 = mtx.get_row(0);
  cout << "row 0 of mtx: ";
  au::print::to_stdout(row0);

  cout << "column 0 of mtx: ";
  vector<int> col0 = mtx.get_col(0);
  au::print::to_stdout(col0);

  // () operator
  int mtx12 = mtx(1, 2);
  cout << "mtx(1, 2) = " << mtx12 << endl;


  // arithmetic operations with matrix
  cout << endl;
  cout << "mtx + other:" << endl;
  cout << mtx + other << endl;

  cout << "mtx - other:" << endl;
  cout << mtx - other << endl;

  return 0;
}
