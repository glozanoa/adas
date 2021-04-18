/*
 * Template binary tree class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H

#include <iostream>
#include <vector>
using namespace std;

#include "helper.hpp"

template<typename T>
class BinaryTree
{
protected:
  T root;
  BinaryTree<T> lchild;
  BinaryTree<T> rchild;
  unsigned int depth;

public:
  BinaryTree(T root)
    :root{root}, depth{0}
  {
    lchild = BinaryTree<T>(root);
    rchild = BinaryTree<T>(root);

    lchild.set_depth(depth+1);
    rchild.set_depth(depth+1);
  }

  BinaryTree(T root, BinaryTree<T> lchild, BinaryTree<T> rchild)
    :root{root}, depth{0}
  {
    lchild.set_depth(depth+1);
    this->lchild = lchild;

    rchild.set_depth(depth+1);
    this->rchild = rchild;
  }

  void set_depth(unsigned int tree_depth){depth = tree_depth;}
  unsigned int get_depth(){return depth;}
  T get_root(){return root;}

  list<BinaryTree<T>> get_children()
  {
    list<BinaryTree<T>> children = list<BinaryTree<T>>(2);
    children[0] = lchild;
    children[1] = rchild;

    return children;
  }

  BinaryTree<T> get_lchild(){return lchild;}
  BinaryTree<T> get_rchild(){return rchild;}

  void add_child(BinaryTree<T> child ,bool is_left_child)
  {
    child.set_depth(depth + 1);
    if(is_left_child)
      lchild = child;
    else
      rchild = child;
  }

  // voif erase_child(T child)
  // {
  //   // check if child exist (HERE)
  //   children->remove(child);
  // }

  friend ostream& operator<<(ostream& out, BinaryTree<T> tree)
  {

    unsigned int depth = tree.get_depth();
    string tab = repeat("\t", depth);
    out << tab << tree.get_root() << endl;

    tab += "\t";
    list<BinaryTree<T>> children = tree.get_children();
    for(BinaryTree<T> child: children)
          out << tab << child;
        out << endl;

    return out;
  }
}


#endif //_BINARY_TREE_H
