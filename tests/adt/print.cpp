#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

#include "../../include/print.hpp"


int main()
{

  vector<int> vec = {1, 5, 4, 0, 7};
  list<int> lst = {5, 0, 4, 9, 3};

  int array[] = {1, 2, 3, 4, 5};
  int N = 5; // numero de elementos del array

  cout << "\nprinting a vector and list (separator ' ')" << endl;

  cout << "vector: ";
  print::to_stdout(vec);

  cout << "list: ";
  print::to_stdout(lst);

  cout << "\nprinting a vector, list and array using iterators(separator ' ')" << endl;

  cout << "vector: ";
  print::to_stdout(vec.begin(), vec.end());

  cout << "list: ";
  print::to_stdout(lst.begin(), lst.end());

  cout << "array: ";
  print::to_stdout(array, array+N);

  cout << "\nprinting a vector and list using iterators(custom separator)" << endl;
  string split = ",";

  cout << "vector: ";
  print::to_stdout(vec.begin(), vec.end(), split);

  cout << "list: ";
  print::to_stdout(lst.begin(), lst.end(), split);

  cout << "array: ";
  print::to_stdout(array, array+N, split);

  // function print::to_string has similar use that print::to_stdout,
  //but it return a string instead of print to console

  return 0;
}
