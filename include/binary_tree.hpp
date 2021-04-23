/*
 * BinaryTree and BinaryNode template classes
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>
#include <list>
using namespace std;

#include "helper.hpp"
#include "node.hpp"
#include "exceptions/general.hpp"

template<typename T>
class BinaryNode : public Node<T>
{
protected:
  BinaryNode<T>* lchild;
  BinaryNode<T>* rchild;

public:
  BinaryNode(T data)
    :Node<T>(data)
  {
    this->parent = nullptr;
    lchild = nullptr;
    rchild = nullptr;
    this->children = {lchild, rchild};
  }

  BinaryNode(T data, BinaryNode<T>* parent, bool is_left_child)
    : Node<T>(data, parent)
  {
    lchild = nullptr;
    rchild = nullptr;
    this->children = {lchild, rchild};

    parent->add_child(this, is_left_child);
  }

  BinaryNode(T data, BinaryNode<T>* parent, bool is_left_child,
             BinaryNode<T>* lchild_node, BinaryNode<T>* rchild_node)
    :Node<T>(data, parent, is_left_child)
  {
    lchild = lchild_node;
    rchild = rchild_node;
    this->children = {lchild, rchild};
  }

  Node<T>* get_lchild(){return lchild;}
  Node<T>* get_rchild(){return rchild;}

  void add_child(BinaryNode<T>* child, bool is_left_child)
  {
    child->set_depth(this->depth+1);
    child->set_parent(this);

    if(is_left_child)
      lchild = child;
    else
      rchild = child;

    this->children = {lchild, rchild};
  }
};


template<typename T>
class BinaryTree
{
protected:
  BinaryNode<T>* root;

public:
  BinaryTree(T root_data)
  {
    BinaryNode<T>* parent = nullptr;
    BinaryNode<T>* lchild = nullptr;
    BinaryNode<T>* rchild = nullptr;

    root = new BinaryNode<T>(root_data, parent, lchild, rchild);
  }

  BinaryTree(T root_data,  BinaryNode<T>* lchild, BinaryNode<T>* rchild)
  {
    BinaryNode<T>* parent = nullptr;
    root = new BinaryNode<T>(root_data, parent, lchild, rchild);
  }

  BinaryTree(BinaryNode<T>* root): root{root} {}


  list<BinaryNode<T>*> get_root_children(){return root->get_children();}
  BinaryNode<T>* get_root(){return root;}
  BinaryNode<T>* get_root_lchild(){return root->get_lchild();}
  BinaryNode<T>* get_root_rchild(){return root->get_rchild();}

  void add_child(BinaryNode<T>* node, BinaryNode<T>* child, bool is_left_child)
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
        // CHECK IF node belows to the binary tree
        node->add_child(child, is_left_child);
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  static bool is_node(BinaryNode<T>* node, BinaryTree<T> tree);

  // void erase_child(T child)
  // {
  //   // check if child exist (HERE)
  //   children.remove(child);
  // }


  friend ostream& operator<<(ostream& out, BinaryTree<T> tree)
  {
    BinaryNode<T>* root = tree.get_root();
    out << root;
    return out;
  }
};


#endif //_BINARY_TREE_H
