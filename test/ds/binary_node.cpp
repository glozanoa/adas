/*
 * Test of BinaryNode<T> template class
 *
 * Status: DEBUGED - date: May 26 2021
 *
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <string>
#include <iostream>
using namespace std;

#include "adas/ds/node.hpp"
#include "adas/ds/binary_node.hpp"
using namespace adas::ds;

int main()
{
  /* Node structure for testing BinaryNode<T> template class
   * r -- a0
       |   |- b0 (left)
       |   |- c0 (right)
       |
       |- d0
          |- e0
          |- a1
             |- b0
             |- c0
   */

  string node_struct = R"""(
      r -- a0
       |   |- b0 (left)
       |   |- c0 (right)
       |
       |- d0
          |- e0
          |- a1
             |- b0
             |- c0
)""";

  cout << "Binary node structure:\n" << node_struct << endl;


  BinaryNode<int>* r   = new BinaryNode<int>(1);

  BinaryNode<int>* a0  = new BinaryNode<int>(2, r, NT::LEFT_NODE);// NT: node type
  BinaryNode<int>* b0  = new BinaryNode<int>(3, a0, NT::LEFT_NODE);
  BinaryNode<int>* c0  = new BinaryNode<int>(4, a0, NT::RIGHT_NODE);
  BinaryNode<int>* d0  = new BinaryNode<int>(5, r, NT::RIGHT_NODE);


  cout << "root node:" << endl;
  cout << r;

  BinaryNode<int>* p = b0->get_parent();

  cout << "b0's parent node:" << endl;
  cout << p;

  // adding a child to node d0
  BinaryNode<int>* e0 = new BinaryNode<int>(6);
  d0->add_child(e0, NT::LEFT_NODE);

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


  BinaryNode<int>* a1  = new BinaryNode<int>(2, d0, NT::RIGHT_NODE);
  a1->add_child(b0, NT::LEFT_NODE);
  a1->add_child(c0, NT::RIGHT_NODE);

  cout << "(after add a1 to root's children)root node:" << endl;
  cout << r;

  are_equal_nodes = a0->is_equal(a1);

  cout << "(Node<T> method comparison) a0 == a1 : " << are_equal_nodes << endl;

  // pointer comparison
  if(a0 == a1) are_equal_nodes = true;
  else are_equal_nodes = false;

  cout << "(pointer comparison) a0 == a1: " << are_equal_nodes << endl;

  return 0;

}
