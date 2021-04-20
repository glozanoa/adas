/*
 * Template binary tree class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>
#include <list>
using namespace std;

#include "helper.hpp"

template<typename T>
class BinaryTree
{
protected:
  T root;
  T data;
  BinaryTree<T>* lchild;
  BinaryTree<T>* rchild;
  list<BinaryTree<T>*> children; // children = {lchild, rchild};
  unsigned int depth;

public:
  BinaryTree(T root)
    :root{root}, data{root}, depth{0}
  {
    lchild = nullptr;
    rchild = nullptr;
    children = {lchild, rchild};
  }

  BinaryTree(T root, BinaryTree<T>* tree_lchild, BinaryTree<T>* tree_rchild)
    :root{root}, data{root}, depth{0}
  {
    lchild = tree_lchild;
    rchild = tree_rchild;
    children = {lchild, rchild};
    for(BinaryTree<T>* child: children)
      if(child != nullptr)
        {
          child->set_root(root);
          child->set_depth(depth+1);
        }
  }

  void set_root(T tree_root)
  {
    root = tree_root;
    for(BinaryTree<T>* child: children)
      if(child != nullptr)
        child->set_root(tree_root);
  }

  void set_depth(unsigned int tree_depth)
  {
    depth = tree_depth;
    for(BinaryTree<T>* child: children)
      if(child != nullptr)
        child->set_depth(depth +1);
  }

  unsigned int get_depth(){return depth;}
  T get_root(){return root;}
  T get_data(){return data;}

  list<BinaryTree<T>*> get_children(){return children;}
  BinaryTree<T>* get_lchild(){return lchild;}
  BinaryTree<T>* get_rchild(){return rchild;}

  void add_child(BinaryTree<T>* child ,bool is_left_child)
  {
    if(child != nullptr)
      {
        child->set_root(root);
        child->set_depth(depth + 1);

        if(is_left_child)
          lchild = child;
        else
          rchild = child;

        children = {lchild, rchild};
      }
    else
      cout << "child tree is nullptr" << endl;
  }

  void erase_child(T child)
  {
    // check if child exist (HERE)
    children.remove(child);
  }


  friend ostream& operator<<(ostream& out, BinaryTree<T> tree)
  {
    unsigned int depth = tree.get_depth();
    string tab = repeat("\t", depth);
    out << tab << tree.get_data() << endl;

    tab += "\t";
    list<BinaryTree<T>*> children = tree.get_children();
    for(BinaryTree<T>* child: children)
      {
        if(child != nullptr)
          out << tab << *child;
      }
    return out;
  }

  friend ostream& operator<<(ostream& out, BinaryTree<T>* tree)
  {
    unsigned int depth = tree->get_depth();
    string tab = repeat("\t", depth);
    out << tab << tree->get_data() << endl;

    tab += "\t";
    list<BinaryTree<T>*> children = tree->get_children();
    for(BinaryTree<T>* child: children)
      {
        if(child != nullptr)
          out << tab << child;
      }
    return out;
  }
};


#endif //_BINARY_TREE_H
