/*
 * Test of binary tree base class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "../../include/binary_tree.hpp"
//#include "../../include/timer.hpp"


int main()
{

  BinaryTree<int>* r   = new BinaryTree<int>(1);
  BinaryTree<int>* c0  = new BinaryTree<int>(2);
  BinaryTree<int>* c1  = new BinaryTree<int>(2+1);
  BinaryTree<int>* c2  = new BinaryTree<int>(2+2);
  BinaryTree<int>* c21 = new BinaryTree<int>(2+2+1);
  BinaryTree<int>* c22 = new BinaryTree<int>(2+2+2);
  BinaryTree<int>* d0  = new BinaryTree<int>(3);
  BinaryTree<int>* d1  = new BinaryTree<int>(3+1);
  BinaryTree<int>* d2  = new BinaryTree<int>(3+2);

  int root = r->get_root();
  cout << "root (r tree): " << root << endl;

  c2->add_child(c21, true);  // left child
  c2->add_child(c22, false); // rigth child

  c0->add_child(c1, true);
  c0->add_child(c2, false);

  d0->add_child(d1, true);
  d0->add_child(d2, false);

  r->add_child(c0, true);
  r->add_child(d0, false);

  cout << r << endl;

  return 0;
}
