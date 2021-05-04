/*
 * Helper function for sort.hpp
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _HELPER_H
#define _HELPER_H

#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <cmath>
#include "omp.h"
using namespace std;

#include "cast.hpp"

//tested - date May 1 2021
template<class InputIterator>
void interchange_values(InputIterator itr1, InputIterator itr2)
{
  auto aux = *itr1;
  *itr1 = *itr2;
  *itr2 = aux;
}

//tested - date May 1 2021
string repeat(string str, int n)
{
  string repeat_str= "";
  for(int k=0; k<n; k++)
    repeat_str += str;

  return repeat_str;
}

//tested - date May 1 2021
unsigned int three_smooth(int p, int q)
/*
 * return 2**p * 3**q
 */
{
  return pow(2, p)*pow(3, q);
}

// MOVE TO search.hpp header file
//tested - date May 1 2021
template<class Iterator>
Iterator minimum(Iterator first, Iterator last)
{
  Iterator min = first;
  Iterator itr = first;
  while(++itr != last)
    {
      if(*itr < *min)
        min = itr;
    }
  return min;
}

// void print_file(ifstream file)
// {
//   //file.open();
//   string line;
//   while(getline(file, line))
//     {
//       cout << line << endl;
//     }
//   file.close();
// }

// template<typename T>
// T readline(ifstream file)
// {
//   string line;

//   getline(file, line);
//   T r = str2<T>(line); // cast string to T type

//   return r;
// }

#endif //_HELPER_H
