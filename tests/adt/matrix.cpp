/*
 * Test of matrix template class
 *
 * Status: 
 * 
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "../../include/matrix.hpp"
#include "../../include/print.hpp"

int main()
{

  vector<int> data1 = {1, 2, 3, 4, 5, 6};
  Matrix<int> mtx = Matrix<int>(2, 3, data1);

  vector<int> data2 = {5, 3, 1, 0, 2, 7};
  Matrix<int> other = Matrix<int>(2, 3, data2);

  // << operator for Matrix<T>
  cout << "mtx:" << endl;
  cout << mtx << endl;

  cout << "other:" << endl;
  cout << other << endl;

  // operation with matrix rows and columns
  vector<int> row0 = mtx.get_row(0);
  cout << "row 0 of mtx: ";
  print::to_stdout(row0);

  cout << "column 0 of mtx: ";
  vector<int> col0 = mtx.get_col(0);
  print::to_stdout(col0);

  // () operator

  int mtx12 = mtx(1, 2);
  cout << "mtx(1, 2) = " << mtx12 << endl;


  //omp_set_num_threads(4);
  // arithmetic operations with matrix
  cout << endl;
  cout << "mtx + other:" << endl;
  cout << mtx + other << endl;

  cout << "mtx - other:" << endl;
  cout << mtx - other << endl;

  return 0;
}
