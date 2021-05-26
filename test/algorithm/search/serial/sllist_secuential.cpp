/*
 * Testing secuential search algorithm in SLList<T> data structure
 *
 * Status: DEBUGGED - date: May 26 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/ds/single_linked_list.hpp"
namespace ads = adas::ds;

#include "adas/algorithm/search/serial.hpp"
namespace ases = adas::algorithm::search::serial;

int main()
{
  ads::SLList<int> list = {72, 64, 50, 23, 84, 18, 37, 99, 45, 8};
  int value = 84;
  cout << "Searching SLNode with key=" << value << " inside a SLList" << endl;
  au::print::to_stdout("list:\n", list, "\n");

  ads::SLList<int>::iterator it = ases::secuential<ads::SLList<int>, int>(list.begin(), list.end(), value);

  if(it == list.end())
    cout << "iterator is end (" << value << " isn't an element of list)" << endl;
  else
    cout << "node: " << it->get_node() << endl;

  return 0;
}
