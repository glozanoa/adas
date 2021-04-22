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
  //string split = ",";

  cout << "print vector" << endl;
  Print<vector<int>::iterator>::to_stdout(vec.begin(), vec.end());

  cout << "print list" << endl;
  Print<list<int>::iterator>::to_stdout(lst.begin(), lst.end());

  return 0;
}
