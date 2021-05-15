/*
 * BST template class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */



#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <vector>
using namespace std;

#include "binary_tree.hpp"

namespace adas::ds
{
  template<class T>
  class BST : public BinaryTree<T>
  {
  public:
    BST(T root_key): BinaryTree<T>(root_key) {}
    BST(vector<T> keys)
      :BinaryTree<T>(keys[0])
    {
      for(unsigned int k = 1; k<keys.size(); k++)
        this->insert(keys[k]);
    }

    void insert(T key)
    {
      BinaryNode<T>* leaf = new BinaryNode<T>(key);
      BinaryNode<T>* parent = BST<T>::search_parent(this->root, leaf);

      T parent_key = parent->get_key();
      if(parent_key < key)
        parent->add_child(leaf, NT::RIGHT_NODE);
      else
        parent->add_child(leaf, NT::LEFT_NODE);
    }

    static BinaryNode<T>* search_parent(BinaryNode<T>* node, BinaryNode<T>* leaf)
    /*
     * Search a parent node for leaf node, to insert leaf into BST
     */
    {
      T node_key = node->get_key();
      T leaf_key = leaf->get_key();

      if(leaf_key == node_key)
        {
          cout << "key=" << leaf_key << " is already in BST" << endl;
          return node;
        }
      else if(leaf_key < node_key)
        {
          BinaryNode<T>* lchild  = node->get_child(NT::LEFT_NODE);
          if(lchild == nullptr)
            return node;
          else
            return search_parent(lchild, leaf);
        }
      else
        {
          BinaryNode<T>* rchild  = node->get_child(NT::RIGHT_NODE);
          if(rchild == nullptr)
            return node;
          else
            return search_parent(rchild, leaf);
        }
    }

    BinaryNode<T>* search(T key)
    /*
     * Search 'key' in Binary Tree and return a pointer to the node who has that key
     */
    {
      return this->search(this->root, key);
    }

    BinaryNode<T>* search(BinaryNode<T>* node, T key)
    /*
     * Search 'key' in Binary Tree and return a pointer to the node who has that key
     * and return nullptr if no one has 'key' as its key
     * But start searching from node (and search recursively in its children)
     */
    {
      T node_key = node->get_key();

      if(node_key == key)
        return node;
      else if(node_key < key)
        {
          BinaryNode<T>* rchild = node->get_child(NT::RIGHT_NODE);
          if(rchild == nullptr)
            return nullptr;
          else
            return search(rchild, key);
        }
      else
        {
          BinaryNode<T>* lchild = node->get_child(NT::LEFT_NODE);
          if(lchild == nullptr)
            return nullptr;
          else
            return search(lchild, key);
        }
    }
  };
}


#endif //_BST_H
