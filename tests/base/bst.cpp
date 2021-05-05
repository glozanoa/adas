/*
 * Test of BST class
 *
 * State = Implemented - date: mar 5 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;


#include "../../include/bst.hpp"


int main()
{
  vector<int> keys = {49, 46, 79, 43, 64, 83};

  BST<int> bst = BST<int>(keys);

  cout << "bst:" << endl;
  cout << bst;

  return 0;
}
