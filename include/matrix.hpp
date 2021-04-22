/*
 * Template matrix class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

//#include "omp"

#include "helper.hpp"
#include "exceptions/matrix.hpp"

template<typename T>
class Matrix
{
protected:
  vector<vector<T>>* data;
  unsigned int nrows;
  unsigned int ncols;

public:
  Matrix()
    :nrows{0},ncols{0}
  {
    data = new vector<vector<T>>(ncols, vector<T>(nrows));
  }

  Matrix(unsigned int rows, unsigned int cols)
    :nrows{rows},ncols{cols}
  {
    data = new vector<vector<T>>(nrows, vector<T>(ncols, 0));
  }

  Matrix(unsigned int rows, unsigned int cols, T value)
    :nrows{rows},ncols{cols}
  {
    data = new vector<vector<T>>(nrows, vector<T>(ncols, value));
  }

  // tested - date Apr 22 2021
  Matrix(unsigned int rows, unsigned int cols, vector<T> values)
  {
    try
      {
        unsigned int size = values.size();
        if(size != rows*cols)
          throw InvalidDim(rows, cols, size);

        ncols = cols;
        nrows = rows;
        data = new vector<vector<T>>(nrows, vector<T>(ncols));

        unsigned int i = 0; // row index
        unsigned int j = 0; // col index
        T aij; // element aij

        for(int k=0; k<size; k++)
          {
            aij = values[k];
            this->set_value(i, j, aij);
            j++;
            if (j == ncols)
              {
                j = 0;
                i++;
              }
          }
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  // tested - date Apr 22 2021
  void set_value(unsigned int row_index, unsigned int col_index, T value)
  {
    try
      {
        if(row_index >= nrows || col_index >= ncols)
          throw InvalidIndex(row_index, col_index);

        data->at(row_index)[col_index] = value;
      }
    catch(InvalidIndex& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  unsigned int get_nrows(){return nrows;}
  unsigned int get_ncols(){return ncols;}

  // tested - date Apr 22 2021
  vector<T> get_row(unsigned int index)
  {
    try
      {
        if(index < nrows)
          return data->at(index);

        else
          throw new InvalidIndex(index, -1); // is_row_index=true
      }
    catch(InvalidIndex& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  // tested - date Apr 22 2021
  vector<T> get_col(unsigned int index)
  {
    vector<T> col;
    try
      {
        if(index < nrows)
          {
            for(int i=0; i<nrows; i++)
              col.push_back(data->at(i)[index]);
            return col;
          }
        else
          throw new InvalidIndex(-1, index); // is_row_index=false
      }
    catch(InvalidIndex& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  // tested - date Apr 22 2021
  T operator()(unsigned int row, unsigned int col)
  {
    try
      {
        if(row >= nrows || col >= ncols)
          throw InvalidIndex(row, col);

        T element = data->at(row)[col];
        return element;
      }
    catch(InvalidIndex& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  // tested - date Apr 22 2021
  Matrix<T> operator+(Matrix<T> mtx)
  {
    try
      {
        unsigned int mtx_nrows = mtx.get_nrows();
        unsigned int mtx_ncols = mtx.get_ncols();
        if(nrows!= mtx_nrows || ncols != mtx_ncols)
          throw InvalidDim(nrows, ncols, mtx_nrows, mtx_ncols);
        else
          {
            Matrix<T> sum = Matrix<T>(nrows, ncols);

            //#pragma omp parallel shared(sum)
            for(unsigned int i=0; i<nrows; i++)
              {
                for(unsigned int j=0; j<ncols; j++)
                  sum.set_value(i, j, data->at(i)[j]+mtx(i, j));
              }
            return sum;
          }
      }
    catch(InvalidDim& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  // tested - date Apr 22 2021
  Matrix<T> operator-(Matrix<T> mtx)
  {
    try
      {
        unsigned int mtx_nrows = mtx.get_nrows();
        unsigned int mtx_ncols = mtx.get_ncols();
        if(nrows!= mtx_nrows || ncols != mtx_ncols)
          throw InvalidDim(nrows, ncols, mtx_nrows, mtx_ncols);
        else
          {
            Matrix<T> subs = Matrix<T>(nrows, ncols);

            //#pragma omp parallel shared(sum)
            for(unsigned int i=0; i<nrows; i++)
              {
                for(unsigned int j=0; j<ncols; j++)
                  subs.set_value(i, j, data->at(i)[j]-mtx(i, j));
              }
            return subs;
          }
      }
    catch(InvalidDim& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }


  // tested - date Apr 22 2021
  friend ostream& operator<<(ostream& out, Matrix<T> mtx)
  {
    for(unsigned int i=0; i<mtx.get_nrows(); i++)
      {
        for(unsigned int j=0; j<mtx.get_ncols(); j++)
          out << mtx(i, j) << " ";
        out << endl;
      }
    return out;
  }
};

#endif //_MATRIX_H
