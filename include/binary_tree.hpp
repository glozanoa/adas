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
class BinaryBranch
{
private:
  T data;
  unsigned int depth;
  BinaryBranch<T>* parent;
  BinaryBranch<T>* lbranch;
  BinaryBranch<T>* rbranch;
  list<BinaryBranch<T>*> branches; // branches = {lbranch, rbranch}

public:
  BinaryBranch(BinaryBranch<T>* parent, T data)
    :parent{parent}, data{data}
  {
    if(parent != nullptr)
      depth = parent->get_depth() +1;
    else
      depth = 0;

    lchild = nullptr;
    rchild = nullptr;
    children = {lchild, rchild};
  }

  BinaryBranch(T data)
  {
    BinaryBranch(nullptr, data);
  }
}

template<typename T>
class BinaryTree
{
protected:
  T root;
  unsigned int depth;
  BinaryBranch<T>* lbranch;
  BinaryBranch<T>* rbranch;
  list<BinaryBranch<T>*> branches; // branches = {lbranch, rbranch};

public:
  BinaryTree(T root)
    :root{root}, depth{0}
  {
    lbranch = nullptr;
    rbranch = nullptr;
    branches = {lbranch, rbranch};
  }

  BinaryTree(T* parent , T data,  BinaryTree<T>* tree_lchild, BinaryTree<T>* tree_rchild)
    :parent{parent}, data{data}, depth{0}
  {
    lchild = tree_lchild;
    rchild = tree_rchild;
    children = {lchild, rchild};
    for(BinaryTree<T>* child: children)
      if(child != nullptr)
        {
          child->set_parent(&data);
          child->set_depth(depth+1);
        }
  }

  void set_parent(T* parent_data)
  {
    parent = parent_data;
  }

  void set_depth(unsigned int tree_depth)
  {
    depth = tree_depth;
    for(BinaryTree<T>* child: children)
      if(child != nullptr)
        child->set_depth(depth +1);
  }

  unsigned int get_depth(){return depth;}
  T* get_parent(){return parent;}
  T get_data(){return data;}

  list<BinaryTree<T>*> get_children(){return children;}
  BinaryTree<T>* get_lchild(){return lchild;}
  BinaryTree<T>* get_rchild(){return rchild;}

  void add_child(BinaryTree<T>* child ,bool is_left_child)
  {
    if(child != nullptr)
      {
        child->set_parent(data);
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
