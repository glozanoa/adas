/*
 * Test of function in helper.hpp header file
 */

#include <iostream>
#include <string>
using namespace std;

#include "../../include/helper.hpp"
#include "../../include/print.hpp"

int main()
{
  string simple = "hi";
  string compound = repeat(simple, 3);

  cout << "3*" << simple  << " : " << compound << endl;

  vector<int> numbers = {3, 2, 5, 1, 6};

  vector<int>::iterator min = minimum(numbers.begin(), numbers.end());

  print::to_stdout(numbers);
  cout << "Minimum: " << *min << endl;


  /*  print */
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


  return 0;
}
