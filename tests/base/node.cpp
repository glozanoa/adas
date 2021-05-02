/*
 * Testing Node template class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/node.hpp"


int main()
{
  /* Node structure for testing Node<T> template class
   * r -- a0
       |   |- b0
       |   |- c0
       |
       |- d0
       |   |- e0
       |
       |- a1
       |   |- b0
       |   |- c0
   */

  Node<int>* r = new Node<int>(1);

  Node<int>* a0  = new Node<int>(2, r);
  Node<int>* b0  = new Node<int>(3, a0);
  Node<int>* c0  = new Node<int>(4, a0);
  Node<int>* d0  = new Node<int>(5, r);


  cout << "root node:" << endl;
  cout << r;

  Node<int>* p = b0->get_parent();

  cout << "b0's parent node:" << endl;
  cout << p;

  // adding a child to node d0
  Node<int>* e0 = new Node<int>(6);
  d0->add_child(e0);

  cout << "(after add e0 to d0) root node:" << endl;
  cout << r;

  //check if b0 is an a0's children
  bool is_child = a0->has_child(b0);
  cout << "Is b0 a0's child?: " << is_child << endl;

  // check if a0 and d0 have equal children
  bool equal_children = a0->equal_children(d0);
  cout << "Do a0 and d0 have equal children?: " << equal_children << endl;

  //comparing 2 nodes
  //(full comparison: parent comparison, children comparison and comparison to itself)
  bool are_equal_nodes = a0->is_equal(r);

  cout << "a0 == r : " << are_equal_nodes << endl;


  Node<int>* a1  = new Node<int>(2, r);
  a1->add_child(b0);
  a1->add_child(c0);

  cout << "(after add a1 to root's children)root node:" << endl;
  cout << r;

  // NOTE: Segmentation fault ERROR - REMOVE IT  (date: May 2 2021)
  // are_equal_nodes = a0->is_equal(a1);

  // cout << "a0 == a1 : " << are_equal_nodes << endl;

  // pointer comparison
  if(a0 == a1)
    cout << "(pointer comparison) a0 == a1" << endl;
  else
    cout << "(pointer comparison) a0 != a1" << endl;

  return 0;
}
