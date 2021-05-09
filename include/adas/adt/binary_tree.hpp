/*
 * BinaryTree template classes
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>
#include <list>
using namespace std;

#include "binary_node.hpp"
#include "exceptions/general.hpp"


template<class T>
class BinaryTree
{
protected:
  BinaryNode<T>* root;

public:
  BinaryTree(T root_key)
  {
    root = new BinaryNode<T>(root_key);
  }

  BinaryTree(T root_key,  BinaryNode<T>* lchild, BinaryNode<T>* rchild)
  {
    BinaryNode<T>* parent = nullptr;
    root = new BinaryNode<T>(root_key, parent, NT::NONE, lchild, rchild);
  }

  BinaryTree(BinaryNode<T>* root): root{root} {}

  list<BinaryNode<T>*> get_children(BinaryNode<T>* node)
  {
    try
      {
        if(!this->is_node(node))
          throw Exception("Node doesn't exist in binary tree");

        return node->get_children();
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        list<BinaryNode<T>*> null_children = {nullptr, nullptr};
        return null_children;
      }
  }
  BinaryNode<T>* get_root(){return root;}

  BinaryNode<T>* get_child(BinaryNode<T>* node, NT type)
  {
    try
      {
        if(!this->is_node(node))
          throw Exception("Node doesn't exist in binary tree");

        return node->get_child(type);
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        BinaryNode<T>* null_child = nullptr;
        return null_child;
      }
  }

  BinaryNode<T>* get_parent(BinaryNode<T>* node)
  {
    try
      {
        if(!this->is_node(node))
          throw Exception("Node doesn't exist in binary tree");

        return node->get_parent();
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        BinaryNode<T>* null_child = nullptr;
        return null_child;
      }
  }


  void add_child(BinaryNode<T>* node, BinaryNode<T>* child, NT type)
  {
    try
      {
        if(node == nullptr || child == nullptr)
          {
            if(node == nullptr)
              throw Exception("I can't add a child node to a nullptr node");
            else
              throw Exception("Invalid: Adding a nullptr child node");
          }
        if(!this->is_node(node))
          throw Exception("Node doesn't exist in binary tree");

        node->add_child(child, type);
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  bool is_node(BinaryNode<T>* node)
  {
    //IMPROVE PERFORMANCE OF Node<T>::has_child method (implement a BINARY SEARCH)
    for(BinaryNode<T>* child : root->get_children())
      if(child->is_equal(node) || node->has_child(node))
        return true;
    return false;
  }

  // void erase_child(T child)
  // {
  //   // check if child exist (HERE)
  //   children.remove(child);
  // }


  friend ostream& operator<<(ostream& out, BinaryTree<T>* tree)
  {
    BinaryNode<T>* root = tree->get_root();
    out << root;
    return out;
  }

  friend ostream& operator<<(ostream& out, BinaryTree<T> tree)
  {
    BinaryNode<T>* root = tree.get_root();
    out << root;
    return out;
  }
};


#endif //_BINARY_TREE_H
