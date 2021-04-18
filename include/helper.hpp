/*
 * Helper function for sort.hpp
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _HELPER_H
#define _HELPER_H

#include <vector>
#include <fstream>
#include "cast.hpp"

// helper functions
template<typename T>
void print(vector<T> elements)
/*
 * print vector in list form
 */
{
  for(T element: elements)
    cout << element << ", ";
  cout  << endl;
}

void print_file(ifstream file)
{
  //file.open();
  string line;
  while(getline(file, line))
    {
      cout << line << endl;
    }
  file.close();
}

template<typename T>
T readline(ifstream file)
{
  string line;

  getline(file, line);
  T r = str2<T>(line); // cast string to T type

  return r;
}

#endif //_HELPER_H
