/*
 * Exceptions to manage general exceptions
 */


#ifndef _GENERAL_EXCEPTIONS_H
#define _GENERAL_EXCEPTIONS_H

#include <string>

class Exception : public std::exception
{
private:
  string warning;

public:
  Exception(string warning)
  {
    this->warning = warning;
  }
  //InvalidIndex(int index, bool is_row_index);
  const char* what() const throw();
};

const char* Exception::what() const throw()
{
  return warning.c_str();
}

#endif //_GENERAL_EXCEPTIONS_H
