/*
 * Testing DLList template class
 *
 * Status: DEBUGGED - date: May 15 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "adas/ds/double_linked_list.hpp"
using namespace adas::ds;


int main()
{
  /*
   * List Structure
   nullptr <- a(key:1) <-> b (key:3) <-> c (key:0) -> nullptr
  */

  DLList<int> list; //empty list
  cout << "Empty list:" << endl;
  cout << list << endl;

  list.push_back(3); // adding 1 element with key 3

  cout << "After push back an element with key 3" << endl;
  cout << list << endl;

  list.push_front(2);
  cout << "After push front an element with key 2" << endl;
  cout << list << endl;


  DLList<int> other = DLList<int>(4, 1); //list of 4 nodes with key 1
  cout << "Initialized list of 4 nodes with key 1" << endl;
  cout << other << endl;

  other.push_back(3); // adding 1 element with key 3
  cout << "After push back an element with key 3" << endl;
  cout << other << endl;

  other.push_front(2);
  cout << "After push back an element with key 2" << endl;
  cout << other << endl;

  return 0;
}
