/*
 * Testing SLList<T>(initializer_list<T> keys) contructor
 *
 * Status:
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/ds/single_linked_list.hpp"
using namespace adas::ds;


int main()
{
  SLList<int> list = {1, 5, 3, 7, 2, 0};

  cout << "list size: " << list.get_size() << endl;
  au::print::to_stdout("Initialized list:\n", list, "\n");

  return 0;
}
