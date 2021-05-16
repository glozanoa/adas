/*
 * Testing DLList template class
 *
 * Status: DEBUGGED - date: May 15 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/ds/double_linked_list.hpp"
using namespace adas::ds;


int main()
{
  /*
   * List Structure
   nullptr <- a(key:1) <-> b (key:3) <-> c (key:0) -> nullptr
  */

  cout << "Init empty list" << endl;
  DLList<int> list; //empty list

  list.push_back(3); // adding 1 element with key 3

  au::print::to_stdout("After push back an element with key 3:\n", list, "\n");

  list.push_front(2);
  au::print::to_stdout("After push front an element with key 2:\n", list, "\n");

  return 0;
}
