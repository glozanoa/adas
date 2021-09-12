/*
 * Test of tree base class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "adas/ds/tree.hpp"

int main()
{
  Tree<int> r = Tree<int>(1);
  Tree<int> c0 = Tree<int>(2);
  Tree<int> c1 = Tree<int>(2+1);
  Tree<int> c2 = Tree<int>(2+2);
  Tree<int> c21 = Tree<int>(2+2+1);
  Tree<int> c22 = Tree<int>(2+2+2);
  Tree<int> d0 = Tree<int>(3);
  Tree<int> d1 = Tree<int>(3+1);
  Tree<int> d2 = Tree<int>(3+2);

  int root = r.get_root();
  cout << "root (r tree): " << root << endl;

  c2.add_child(&c21);
  c2.add_child(&c22);

  c0.add_child(&c1);
  c0.add_child(&c2);

  d0.add_child(&d1);
  d0.add_child(&d2);

  r.add_child(&c0);
  r.add_child(&d0);

  cout << r << endl;

  return 0;
}
