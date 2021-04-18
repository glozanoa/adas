/*
 * Test of tree base class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <vector>
using namespace std;

#include "../../include/tree.hpp"
//#include "../../include/timer.hpp"


int main()
{
  Tree<int> r = Tree<int>(1);
  Tree<int> c = Tree<int>(2);

  int root = r.get_root();
  cout << "root (r tree): " << root << endl;

  r.add_child(c);

  cout << r << endl;

  return 0;
}
