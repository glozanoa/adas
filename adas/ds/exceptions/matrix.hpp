/*
 * Matrix exceptions
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _MATRIX_EXCEPT_H
#define _MATRIX_EXCEPT_H

#include <string>

/*----------- InvalidIndex -----------*/

class InvalidIndex : public std::exception
{
private:
  int row;
  int col;

public:
  InvalidIndex(int row_index, int col_index);
  //InvalidIndex(int index, bool is_row_index);
  const char* what() const throw();
};


InvalidIndex::InvalidIndex(int row_index, int col_index)
{
  row = row_index;
  col = col_index;
}
// InvalidIndex::InvalidIndex(int index, bool is_row_index)
// {
//   if(is_row_index)
//     {
//       row = index;
//       col = -1;
//     }
//   else
//     {
//       row = -1;
//       col = index;
//     }
// }

const char* InvalidIndex::what() const throw()
{
  string warning ="";

  if(row >= 0 && col == -1) // rown index exception
    warning = "Invalid matrix row index: " + to_string(row) + "\n";

  else if(row == -1 && col >= 0) // rown index exception
    warning = "Invalid matrix column index: " + to_string(col) + "\n";

  else //if(row != 0 && col != 0) // element index exception
    warning = "Invalid Index: (" + to_string(row) + ", " + to_string(col) + ")\n";

  return warning.c_str();
}

/*----------- InvalidDim -----------*/

class InvalidDim : public std::exception
{
private:
  string warning;

public:
  InvalidDim(unsigned int nrows, unsigned int ncols, unsigned int size);
  InvalidDim(unsigned int nrows1, unsigned int ncols1,
             unsigned int nrows2, unsigned int ncols2);
  const char* what() const throw();
};

InvalidDim::InvalidDim(unsigned int nrows, unsigned int ncols, unsigned int size)
{
  warning = "I can't fill a matrix of dimension ";
  warning += "(" + to_string(nrows) + ", " + to_string(ncols) + ") with ";
  warning += to_string(size) + " elements\n";
}

InvalidDim::InvalidDim(unsigned int nrows1, unsigned int ncols1,
                       unsigned int nrows2, unsigned int ncols2)
{
  warning = "I can't operate matrixes of distint dimensions:  ";
  warning += "(" + to_string(nrows1) + " x " + to_string(ncols1) + ") and  ";
  warning += "(" + to_string(nrows2) + " x " + to_string(ncols2) + ")";
}

const char* InvalidDim::what() const throw()
{
  return warning.c_str();
}


#endif //_MATRIX_EXCEPT_H
