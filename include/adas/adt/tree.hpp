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


// NOTE: CHANGE ROOT BY PARENT ATTRIBUTE
template<typename T>
class Tree
{
protected:
  T* parent;
  T data;
  unsigned int depth;
  list<Tree<T>*> children;

public:
  Tree(T data): parent{nullptr}, data{data}, depth{0} {}
  Tree(T* parent, T data):parent{parent}, data{data}, depth{0} {}

  Tree(T* parent, list<Tree<T>*> tree_children)
    :parent{parent}, depth{0}, data{root}
  {
    for(Tree<T>* child: tree_children)
      if(child != nullptr)
        {
          child->set_parent(root);
          child->set_depth(depth+1);
        }

    children = tree_children;
  }

  void set_parent(T tree_parent)
  {
    parent = tree_parent;
    for(Tree<T>* child: children)
      if (child != nullptr)
        child->set_parent(tree_root);
  }
  void set_depth(unsigned int tree_depth)
  {
    depth = tree_depth;
    for(Tree<T>* child: children)
      if (child != nullptr)
        child->set_depth(depth +1);
  }
  unsigned int get_depth(){return depth;}
  T get_root(){return root;}
  T get_data(){return data;}
  list<Tree<T>*> get_children(){return children;}

  void add_child(Tree<T>* child)
  {
    if(child != nullptr)
      {
        child->set_root(root);
        child->set_depth(depth + 1);
        children.push_back(child);
      }
    else
      {
        cout << "child tree is nullptr" << endl;
      }
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
    out << tab << tree.get_data() << endl;

    tab += "\t";
    list<Tree<T>*> children = tree.get_children();
    for(Tree<T>* child: children)
      {
        if(child != nullptr)
          out << tab << *child;
      }

    return out;
  }
};


#endif //_TREE_H
