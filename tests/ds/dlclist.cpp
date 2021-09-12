/*
 * Testing DLCList template class
 *
 * NOTE: Don't print DLCList with adas::utilities::print::to_stdout fuction because DLList hasn't an end iterator
 *
 * Status: DEBUGGED - date: May 27 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/ds/doubly_linked_circular_list.hpp"
using namespace adas::ds;


int main()
{
  /*
   * List Structure
   nullptr <- Node(key:2) <-> Node(key:4) <-> Node(key:1) <-> Node(key:3) -> nullptr (UPDATE)
  */

  cout << "Init empty list" << endl;
  DLCList<int> list; //empty list

  list.push_back(3); // adding 1 element with key 3
  list.push_back(2);
  list.push_back(1);

  //DLCList<int>::print_list(list);
  cout << list << endl;
}
