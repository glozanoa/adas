/*
 * Testing SLCList template class
 *
 * NOTE: Don't print SLCList with adas::utilities::print::to_stdout function because SLList hasn't an end iterator
 *
 * Status:
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "adas/utilities.hpp"
namespace au = adas::utilities;

#include "adas/ds/single_linked_circular_list.hpp"
using namespace adas::ds;


int main()
{
  /*
   * List Structure
   nullptr <- Node(key:2) <-> Node(key:4) <-> Node(key:1) <-> Node(key:3) -> nullptr (UPDATE)
  */

  cout << "Init empty list" << endl;
  SLCList<int> list; //empty list

  list.push_back(3); // adding 1 element with key 3
  list.push_back(2);
  list.push_back(1);

  //DLCList<int>::print_list(list);
  cout << list << endl;
}
