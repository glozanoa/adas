/*
 * Testing DLNode template class
 *
 * Status: DEBUGED - date May 15 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "adas/ds/doubly_linked_node.hpp"
using namespace adas::ds;


int main()
{
  /*
   * Node Structure
   nullptr <- a(key:1) <-> b (key:3) <-> c (key:0) -> nullptr
   */

  DLNode<int>* a = new DLNode<int>(1);
  DLNode<int>* b = new DLNode<int>(3);
  DLNode<int>* c = new DLNode<int>(0);

  cout << "a's key:" << a->get_key() << endl;
  cout << "a DLNode (init):" << endl;
  cout << "Node: " << a << ", " << *a << endl;

  a->set_next(b);
  cout << "a DLNode (after linking with b):" << endl;
  cout << "Node a: " << a << ", " << *a << endl;

  b->set_next(c);
  cout << "b DLNode (after linking with c):" << endl;
  cout << "Node b: " << b << ", " << *b << endl;

  cout << "Node c: " << c << ", " << *c << endl;


  return 0;
}
