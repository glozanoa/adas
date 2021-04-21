#include <iostream>
#include <vector>
#include <list>

using namespace std;

#include "../../include/helper.hpp"


int main()
{
  vector<int> vec = {1, 5, 4, 0, 7};
  list<int> lst = {5, 0, 4, 9, 3};

  cout << "print vector" << endl;
  print(vec);

  cout << "print list" << endl;
  print(lst);

  return 0;
}
