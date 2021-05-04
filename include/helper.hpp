/*
 * Helper function for sort.hpp
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _HELPER_H
#define _HELPER_H

#include <iterator>
#include <utility>
#include <cmath>
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

template<class ForwardIterator>
pair<ForwardIterator, ForwardIterator> minmax(ForwardIterator a, ForwardIterator b)
{
  return (*b<*a) ? make_pair(b,a) : make_pair(a,b);
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

#endif //_HELPER_H
