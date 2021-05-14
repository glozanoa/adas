/*
 * Test of binary tree base class
 *
 * Status: Exit with a Segmentation fault (NOTE: DEBUG binary_tree.hpp header file)
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/ds/binary_tree.hpp"


int main()
{

  /* Node structure for testing BinaryTree<T> template class
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


  string binary_tree_struct = R"""(
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

  cout << "Binary tree structure:\n" << binary_tree_struct << endl;

  BinaryNode<int>* a0  = new BinaryNode<int>(2);
  BinaryNode<int>* b0  = new BinaryNode<int>(3, a0, NT::LEFT_NODE);
  BinaryNode<int>* c0  = new BinaryNode<int>(4, a0, NT::RIGHT_NODE);
  BinaryNode<int>* d0  = new BinaryNode<int>(5);


  BinaryTree<int>* bt = new BinaryTree<int>(1, a0, d0);

  cout << "binary tree:" << endl;
  cout << bt;

  BinaryNode<int>* p = bt->get_parent(b0);

  cout << "b0's parent node:" << endl;
  cout << p;

  // adding a child to node d0
  BinaryNode<int>* e0 = new BinaryNode<int>(6);
  bt->add_child(d0, e0, NT::LEFT_NODE);

  cout << "(after add e0 to d0) binary tree:" << endl;
  cout << bt;

  //check if b0 belows to the binary tree
  //bool is_node = bt->is_node(b0);
  //cout << "Is b0 a binary tree's node?: " << is_node << endl;

  // // check if a0 and d0 have equal children
  // bool equal_children = a0->equal_children(d0);
  // cout << "Do a0 and d0 have equal children?: " << equal_children << endl;

  // //comparing 2 nodes
  // //(full comparison: parent comparison, children comparison and comparison to itself)
  // bool are_equal_nodes = a0->is_equal(r);

  // cout << "a0 == r : " << are_equal_nodes << endl;


  // BinaryNode<int>* a1  = new BinaryNode<int>(2, d0, NT::RIGHT_NODE);
  // a1->add_child(b0, NT::LEFT_NODE);
  // a1->add_child(c0, NT::RIGHT_NODE);

  // cout << "(after add a1 to root's children)root node:" << endl;
  // cout << r;

  // // NOTE: Segmentation fault ERROR - REMOVE IT  (date: May 2 2021)
  // are_equal_nodes = a0->is_equal(a1);

  // cout << "(Node<T> method comparison) a0 == a1 : " << are_equal_nodes << endl;

  // // pointer comparison
  // if(a0 == a1) are_equal_nodes = true;
  // else are_equal_nodes = false;

  // cout << "(pointer comparison) a0 == a1: " << are_equal_nodes << endl;

  return 0;
}
