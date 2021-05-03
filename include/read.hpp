/*
 * Function to read number from a file (ONLY FOR TESTING PURPOSE) to a vector
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _READ_H
#define _READ_H

#include <vector>
#include <string>
#include <fstream>
using namespace std;

#include "cast.hpp"

template<class T>
class Read
{
public:
  static vector<T> from_file(string file_name)
  {
    ifstream fn;
    vector<T> numbers;
    try
      {
        fn.open(file_name);
        int number;
        string line;
        while(getline(fn, line))
          {
            number = str2<T>(line);
            numbers.push_back(number);
          }
        fn.close();
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        if(fn.is_open())
          fn.close();
      }
    return numbers;
  }
};

#endif //_READ_H
