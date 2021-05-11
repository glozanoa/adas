/*
 * Test of BST class
 *
 * State = Implemented - date: mar 5 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
using namespace std;

#include "adas/ds/bst.hpp"

int main()
{
  vector<int> keys = {49, 46, 79, 43, 64, 83};

  BST<int> bst = BST<int>(keys);

  cout << "bst:" << endl;
  cout << bst;

  int key = 79;
  cout << "Searching node with key = " << key << endl;
  BinaryNode<int>* node =  bst.search(key);

  if(node == nullptr)
    cout << "key:" << key << ", didn't exist in BST" << endl;
  else
    cout << "key was found" << endl;

  return 0;
}
