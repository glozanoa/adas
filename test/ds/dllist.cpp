/*
 * Testing DLList template class
 *
 * Status: DEBUGGED - date: May 16 2021
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
   nullptr <- Node(key:2) <-> Node(key:4) <-> Node(key:1) <-> Node(key:3) -> nullptr (UPDATE)
  */

  cout << "Init empty list" << endl;
  DLList<int> list; //empty list

  list.push_back(3); // adding 1 element with key 3

  au::print::to_stdout("After push back an element with key 3:\n", list, "\n");

  list.push_front(2);
  au::print::to_stdout("After push front an element with key 2:\n", list, "\n");


  cout << "Inserting  DLNode<T>(5) in position 0" << endl;
  int key = 5;
  DLList<int>::iterator position = list.begin();
  DLList<int>::iterator itr = list.insert(position, key);
  au::print::to_stdout("List after insertion:\n", list, "\n");

  cout << "Changing nodes's key at position 1 by key=1" << endl;
  key = 1;
  list.set_key(list.begin()+1, key);
  au::print::to_stdout("List after changing node's key:\n", list, "\n");

  cout << "Inserting DLNode<T>(4) in position 1" << endl;
  key = 4;
  list.insert(list.begin()+1, key);
  au::print::to_stdout("List after insertion:\n", list, "\n");

  cout << "Erasing element of position 1" << endl;
  list.erase(list.begin()+1);
  au::print::to_stdout("List after erase:\n", list, "\n");

  cout << "Erasing tail" << endl;
  list.pop_back();
  au::print::to_stdout("List after erase tail:\n", list, "\n");

  cout << "Erasing head" << endl;
  list.pop_front();
  au::print::to_stdout("List after erase head:\n", list, "\n");

  return 0;
}
