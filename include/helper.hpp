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


template<class Iterator>
void interchange_values(Iterator itr1, Iterator itr2)
{
  auto aux = *itr1;
  *itr1 = *itr2;
  *itr2 = aux;
}


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

/*template<typename T>
void print(vector<T> elements)
 /*
  * print a container (vector, list, ...) in list form
  
{
  typename T::iterator itr;

  for(itr=elements.begin(); itr!=elements.end();itr++)
  {
    cout << *itr << ", ";
    cout  << endl;
  }
}*/

// duplicate function
// //Funcion print agregada por rubeen
// void print(std::vector<int> const &input){
//   std::copy(input.begin(), input.end(),std::ostream_iterator<int>(std::cout," "));
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
