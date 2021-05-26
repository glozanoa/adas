/*
 * Testing secuential search algorithm in DLList<T> data structure
 *
 * Status: DEBUGGED - date: May 26 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/ds/doubly_linked_list.hpp"
namespace ads = adas::ds;

#include "adas/algorithm/search/serial.hpp"
namespace ases = adas::algorithm::search::serial;

int main()
{
  ads::DLList<int> list = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  int value = 84;

  cout << "Searching SLNode with key=" << value << " inside a DLList" << endl;
  au::print::to_stdout("list:\n", list, "\n");

  ads::DLList<int>::iterator it = ases::secuential<ads::DLList<int>, int>(list.begin(), list.end(), value);

  if(it == list.end())
    cout << "iterator is end (" << value << " isn't an element of list)" << endl;
  else
    cout << "node: " << it->get_node() << endl;

  return 0;
}
