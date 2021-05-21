/*
 * Testing SLNode template class
 *
 * Status: DEBUGED - date May 21 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "adas/ds/single_linked_node.hpp"
using namespace adas::ds;


int main()
{
  /*
   * Node Structure
   nullptr <- a(key:1) <-> b (key:3) <-> c (key:0) -> nullptr
  */

  SLNode<int>* a = new SLNode<int>(1);
  SLNode<int>* b = new SLNode<int>(3);
  SLNode<int>* c = new SLNode<int>(0);

  cout << "a's key:" << a->get_key() << endl;
  cout << "a DLNode (init):" << endl;
  cout << a << endl;

  a->set_next(b);
  cout << "a DLNode (after linking with b):" << endl;
  cout << a << endl;

  b->set_next(c);
  cout << "b DLNode (after linking with c):" << endl;
  cout << b << endl;

  return 0;
}
