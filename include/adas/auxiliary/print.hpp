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

  template<typename T>
  void to_stdout(string prefix, T container)
  {
    cout << prefix + " ";
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
  void to_stdout(string prefix, ForwardIterator first, ForwardIterator last)
  {
    cout << prefix + " ";
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


  template<typename T>
  string to_string(T container)
  {
    string out = "";
    typename T::iterator itr;
    for(itr=container.begin(); itr!=container.end(); itr++)
      out += *itr  + " ";

    return out;
  }

  template<typename T>
  string to_string(T container, string split)
  {
    string out = "";
    typename T::iterator itr;
    for(itr=container.begin(); itr!=container.end(); itr++)
      out += *itr + split + " ";

    return out;
  }
};

#endif //_PRINT_H
