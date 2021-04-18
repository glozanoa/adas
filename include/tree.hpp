/*
 * Template tree class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _TREE_H
#define _TREE_H

#include <iostream>
#include <list>
using namespace std;

#include "helper.hpp"

template<typename T>
class Tree
{
protected:
  T root;
  list<Tree<T>> children;
  unsigned int depth;

public:
  Tree(T root):root{root}, depth{0} {}

  Tree(T root, list<Tree<T>> tree_children)
    :root{root}, depth{0}
  {
    for(Tree<T> child: tree_children)
      child.set_depth(depth+1);

    children = tree_children;
  }

  void set_depth(unsigned int tree_depth){depth = tree_depth;}
  unsigned int get_depth(){return depth;}
  T get_root(){return root;}
  list<Tree<T>> get_children(){return children;}

  void add_child(Tree<T> child)
  {
    child.set_depth(depth + 1);
    children.push_back(child);
  }

  void erase_child(T child)
  {
    // check if child exist (HERE)
    children.remove(child);
  }

  friend ostream& operator<<(ostream& out, Tree<T> tree)
  {
    unsigned int depth = tree.get_depth();
    string tab = repeat("\t", depth);
    out << tab << tree.get_root() << endl;

    tab += "\t";
    list<Tree<T>> children = tree.get_children();
    for(Tree<T> child: children)
          out << tab << child;
        out << endl;

    return out;
  }
};


#endif //_TREE_H
