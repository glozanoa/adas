/*
 * print template class
 *
 * Maintaner: glozanoa <glozanoa@uni.pe>
 */


#ifndef _PRINT_H
#define _PRINT_H

#include <iostream>
#include <string>
using namespace std;


namespace print
{
  template<typename T>
  void to_stdout(T container)
  {
    typename T::iterator itr;
    for(itr=container.begin(); itr!=container.end(); itr++)
      {
        cout << *itr << " ";
      }
    cout << endl;
  }


  template<typename ForwardIterator>
  void to_stdout(ForwardIterator first, ForwardIterator last)
  {
    for(ForwardIterator itr=first; itr!=last; itr++)
      {
        cout << *itr << " ";
      }
    cout << endl;
  }

  template<typename ForwardIterator>
  void to_stdout(ForwardIterator first, ForwardIterator last, string split)
  {
    for(ForwardIterator itr=first; itr!=last; itr++)
      {
        cout << *itr << split << " ";
      }
    cout << endl;
  }

  template<typename ForwardIterator>
  string to_string(ForwardIterator first, ForwardIterator last)
  {
    string out = "";
    for(ForwardIterator itr=first; itr!=last; itr++)
      out += *itr + " ";

    return out;
  }

  template<typename ForwardIterator>
  string to_string(ForwardIterator first, ForwardIterator last, string split)
  {
    string out = "";
    for(ForwardIterator itr=first; itr!=last; itr++)
      out += *itr + split + " ";

    return out;
  }
};

#endif //_PRINT_H
