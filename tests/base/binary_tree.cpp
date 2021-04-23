/*
 * Test of binary tree base class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "../../include/binary_tree.hpp"


int main()
{

  /*  First form of build a binary tree (using BinaryNode class) */


  BinaryNode<int>* r   = new BinaryNode<int>(1);

  BinaryNode<int>* c0  = new BinaryNode<int>(2, r, true);


  BinaryNode<int>* d0  = new BinaryNode<int>(3, r, false);
  BinaryNode<int>* d1  = new BinaryNode<int>(3+1, d0, true);
  BinaryNode<int>* d2  = new BinaryNode<int>(3+2, d0, false);

  BinaryNode<int>* c1  = new BinaryNode<int>(2+1, c0, true);

  BinaryNode<int>* c2  = new BinaryNode<int>(2+2, c0, false);
  BinaryNode<int>* c21 = new BinaryNode<int>(2+2+1, c2, true);
  BinaryNode<int>* c22 = new BinaryNode<int>(2+2+2, c2, false);


  BinaryTree<int> tree = BinaryTree(r);

  cout << tree << endl;


  cout << "r has c0 as its child: " << r->has_child(c0) << endl;

  return 0;
}
