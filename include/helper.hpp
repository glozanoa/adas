/*
 * Helper function for sort.hpp
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _HELPER_H
#define _HELPER_H

#include <vector>
#include <fstream>
#include <cmath>
#include "cast.hpp"

using namespace std;

string repeat(string str, int n)
{
  string repeat_str= "";
  for(int k=0; k<n; k++)
    repeat_str += str;

  return repeat_str;
}

unsigned int three_smooth(int p, int q)
/*
 * return 2**p * 3**q
 */
{
  return pow(2, p)*pow(3, q);
}

template<class RandomAccessIterator>
RandomAccessIterator minimum(RandomAccessIterator first, RandomAccessIterator last)
{
  RandomAccessIterator min = first;
  RandomAccessIterator itr = first;
  while(++itr != last)
    {
      if(*itr < *min)
        min = itr;
    }
  return min;
}


// helper functions

// template<class RandomAccessIterator>
// void print(RandomAccessIterator first, RandomAccessIterator last)
// /*
//  * print a container (vector, list, ...) in list form using iterators
//  */
// {
//   RandomAccessIterator itr;

//   for(itr=first; itr!=last; itr++)
//     cout << *itr << ", ";
//   cout  << endl;
// }

// template<typename T>
// void print(T elements)
// /*
//  * print a container (vector, list, ...) in list form
//  */
// {
//   typename T::iterator itr;

//   for(itr=elements.begin(); itr!=elements.end();itr++)
//     cout << *itr << ", ";
//   cout  << endl;
// }

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
