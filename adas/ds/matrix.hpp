/*
 * Template matrix data structure (ds)
 *
 * State: DEBUGGED - date: May 26 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _MATRIX_H
#define _MATRIX_H

#include <iostream>
#include <vector>
using namespace std;

#include "exceptions/matrix.hpp"

#include "omp.h"

namespace adas::ds
{

  template<typename T>
  class Matrix
  {
  protected:
    vector<vector<T>>* data;
    unsigned int nrows;
    unsigned int ncols;

  public:
    Matrix();
    Matrix(unsigned int rows, unsigned int cols);
    Matrix(unsigned int rows, unsigned int cols, T value);
    Matrix(unsigned int rows, unsigned int cols, vector<T> values);


    /*  methods to manipulate Matrix<T> ds */
    void set_value(unsigned int row_index, unsigned int col_index, T value);
    unsigned int get_nrows(){return nrows;}
    unsigned int get_ncols(){return ncols;}
    vector<T> get_row(unsigned int index);
    vector<T> get_col(unsigned int index);
    T operator()(unsigned int row, unsigned int col);
    Matrix<T> operator+(Matrix<T> mtx);
    Matrix<T> operator-(Matrix<T> mtx);

    template<typename L>
    friend ostream& operator<<(ostream& out, Matrix<L> mtx);
  };

  /*  IMPLEMENTATION Matrix<T> class */

  template<class T>
  Matrix<T>::Matrix()
    :nrows{0}, ncols{0}
  {
    data = new vector<vector<T>>(ncols, vector<T>(nrows));
  }

  template<class T>
  Matrix<T>::Matrix(unsigned int rows, unsigned int cols)
    :nrows{rows}, ncols{cols}
  {
    data = new vector<vector<T>>(nrows, vector<T>(ncols, 0));
  }

  template<class T>
  Matrix<T>::Matrix(unsigned int rows, unsigned int cols, T value)
    :nrows{rows}, ncols{cols}
  {
    data = new vector<vector<T>>(nrows, vector<T>(ncols, value));
  }

  template<class T>
  Matrix<T>::Matrix(unsigned int rows, unsigned int cols, vector<T> values)
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


  template<class T>
  void Matrix<T>::set_value(unsigned int row_index, unsigned int col_index, T value)
  {
    try
      {
        if(nrows <= row_index || ncols <= col_index)
          throw InvalidIndex(row_index, col_index);

        data->at(row_index)[col_index] = value;
      }
    catch(InvalidIndex& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  template<class T>
  vector<T> Matrix<T>::get_row(unsigned int index)
  {
    try
      {
        if(nrows <= index)
          throw new InvalidIndex(index, -1); // is_row_index=true

        return data->at(index);
      }
    catch(InvalidIndex& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  template<class T>
  vector<T> Matrix<T>::get_col(unsigned int index)
  {
    vector<T> col;
    try
      {
        if(ncols <= index)
          throw new InvalidIndex(-1, index); // is_row_index=false

        for(int i=0; i<nrows; i++)
          col.push_back(data->at(i)[index]);
        return col;
      }
    catch(InvalidIndex& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  template<class T>
  T Matrix<T>::operator()(unsigned int row, unsigned int col)
  {
    try
      {
        if(nrows <= row || ncols <= col)
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

  template<class T>
  Matrix<T> Matrix<T>::operator+(Matrix<T> mtx)
    {
      try
        {
          unsigned int mtx_nrows = mtx.get_nrows();
          unsigned int mtx_ncols = mtx.get_ncols();
          if(nrows!= mtx_nrows || ncols != mtx_ncols)
            throw InvalidDim(nrows, ncols, mtx_nrows, mtx_ncols);

          Matrix<T> sum = Matrix<T>(nrows, ncols);

          omp_set_nested(true);
#pragma omp parallel for shared(sum, mtx) firstprivate(nrows, ncols)
          for(unsigned int i=0; i<nrows; i++)
            {
              //unsigned int row_thread = omp_get_thread_num(); // ONLY FOR DEBUG PURPOSE
              vector<T> row = this->get_row(i);
              vector<T> mtx_row = mtx.get_row(i);
#pragma omp parallel for firstprivate(row, mtx_row, ncols)
              for(unsigned int j=0; j<ncols; j++)
                {
                  sum.set_value(i, j, row[j]+mtx_row[j]);
                  // ONLY FOR GEBUG PURPOSE
                  // unsigned int col_thread = omp_get_thread_num();
                  // #pragma omp critical
                  // {
                  //   cout << "Row Thread: " << row_thread << " , Column Thread: " << col_thread  <<
                  //   ", sum(" << i << ", " << j << ") = " << sum(i, j) << endl;
                  // }
                }
            }
          return sum;
        }
      catch(InvalidDim& error)
        {
          cout << error.what() << endl;
          exit(EXIT_FAILURE);
        }
    }


  template<class T>
  Matrix<T> Matrix<T>::operator-(Matrix<T> mtx)
    {
      try
        {
          unsigned int mtx_nrows = mtx.get_nrows();
          unsigned int mtx_ncols = mtx.get_ncols();
          if(nrows!= mtx_nrows || ncols != mtx_ncols)
            throw InvalidDim(nrows, ncols, mtx_nrows, mtx_ncols);

          Matrix<T> subs = Matrix<T>(nrows, ncols);

          //omp_set_nested(true);
#pragma omp parallel for shared(subs, mtx) firstprivate(nrows, ncols)
          for(unsigned int i=0; i<nrows; i++)
            {
              //unsigned int row_thread = omp_get_thread_num(); // ONLY FOR DEBUG PURPOSE
              vector<T> row = this->get_row(i);
              vector<T> mtx_row = mtx.get_row(i);
#pragma omp parallel for firstprivate(row, mtx_row, ncols)
              for(unsigned int j=0; j<ncols; j++)
                {
                  subs.set_value(i, j, row[j]-mtx_row[j]);
                  // ONLY FOR GEBUG PURPOSE
                  // unsigned int col_thread = omp_get_thread_num();
                  // #pragma omp critical
                  // {
                  //   cout << "Row Thread: " << row_thread << " , Column Thread: " << col_thread  <<
                  //   ", subs(" << i << ", " << j << ") = " << subs(i, j) << endl;
                  // }
                }
            }
          return subs;
        }
      catch(InvalidDim& error)
        {
          cout << error.what() << endl;
          exit(EXIT_FAILURE);
        }
    }

  template<class T>
  ostream& operator<<(ostream& out, Matrix<T> mtx)
  {
    for(unsigned int i=0; i < mtx.get_nrows(); i++)
      {
        for(unsigned int j=0; j < mtx.get_ncols(); j++)
          out << mtx(i, j) << " ";
        out << endl;
      }
    return out;
  }


}

#endif //_MATRIX_H
