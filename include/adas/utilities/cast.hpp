/*
 * Cast an string  to (int, double, float, long double) if is posible
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _CAST_H
#define _CAST_H

#include <string>
using namespace std;

namespace adas::utilities
{
  template<typename T>
  T str2(string value)
  /*
   * Try to cast a string to other of type T
   */
  {
    T casted;

    // string to (int, double, ...) casts
    if (is_same<T, int>::value)
      casted = stoi(value);

    else if (is_same<T, double>::value)
      casted = stod(value);

    else if (is_same<T, float>::value)
      casted = stof(value);

    else if (is_same<T, long double>::value)
      casted = stold(value);

    return casted;
  }
}

#endif //_CAST_H
