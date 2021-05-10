/*
 * Test of BSTNode class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "../../include/bst_node.hpp"

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

  BSTNode<int>* r   = new BSTNode<int>(1);

  BSTNode<int>* a0  = new BSTNode<int>(2, r, NT::LEFT_NODE);// NT: node type
  BSTNode<int>* b0  = new BSTNode<int>(3, a0, NT::LEFT_NODE);
  BSTNode<int>* c0  = new BSTNode<int>(4, a0, NT::RIGHT_NODE);
  BSTNode<int>* d0  = new BSTNode<int>(5, r, NT::RIGHT_NODE);


  cout << "root node:" << endl;
  cout << r;

  BSTNode<int>* p = b0->get_parent();

  cout << "b0's parent node:" << endl;
  cout << p;

  // adding a child to node d0
  BSTNode<int>* e0 = new BSTNode<int>(6);
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


  BSTNode<int>* a1  = new BSTNode<int>(2, d0, NT::RIGHT_NODE);
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
