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

  Node<int>* r = new Node<int>(1);

  Node<int>* c0  = new Node<int>(2, r);

  Node<int>* d0  = new Node<int>(3, r);

  // BinaryNode<int>* d1  = new BinaryNode<int>(3+1, d0, true);
  // BinaryNode<int>* d2  = new BinaryNode<int>(3+2, d0, false);

  // BinaryNode<int>* c1  = new BinaryNode<int>(2+1, c0, true);

  // BinaryNode<int>* c2  = new BinaryNode<int>(2+2, c0, false);
  // BinaryNode<int>* c21 = new BinaryNode<int>(2+2+1, c2, true);
  // BinaryNode<int>* c22 = new BinaryNode<int>(2+2+2, c2, false);


  // BinaryTree<int> tree = BinaryTree(r);

  cout << r;

  return 0;
}
