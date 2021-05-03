/*
 * Node Template class
 *
 * Debuged class - May 3 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _NODE_H
#define _NODE_H

#include <list>
using namespace std;

#include "helper.hpp"
#include "exceptions/node.hpp"

template<typename T>
class Node
{
protected:
  T key;
  unsigned int depth;
  Node<T>* parent;
  list<Node<T>*> children;

public:
  Node(T key): key{key}, parent{nullptr}, depth{0} {}
  Node(T key, Node<T>* parent): key{key}, parent{parent}, depth{0}
  {
    parent->add_child(this);
  }

  Node(T key, Node<T>* parent, list<Node<T>*> children)
    : key{key}, parent{parent}, children{children}
  {
    parent->add_child(this);

    for(Node<T>* child: children)
      if(child != nullptr)
        this->add_child(child);
  }

  T get_key(){return key;}
  Node<T>* get_parent(){return parent;}
  void set_depth(unsigned int tree_depth)
  {
    depth = tree_depth;
    for(Node<T>* child: children)
      if(child != nullptr)
        child->set_depth(depth +1);
  }

  list<Node<T>*> get_children(){return children;}
  unsigned int get_depth(){return depth;}

  void add_child(Node<T>* child)
  {
    child->set_depth(depth+1);
    child->set_parent(this);
    children.push_back(child);
  }

  void set_parent(Node<T>* parent)
  {
    try
      {
        if(parent == nullptr)
          throw NullParentNode();

        this->parent = parent;
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
    //parent->add_child(this); // NOTE
  }

  bool equal_children(Node<T>* node)
  {
    // implemnt a more efficient algorithm to compare 2 sets
    // using this theorem:
    // A = B  <-> A c B and |A| = |B|

    list<Node<T>*> node_children = node->get_children();
    if(this->children.size() != node_children.size())
      return false;

    for(Node<T>* child: node_children)
      if(!this->has_child(child))
        return false;

    return true;
  }

  bool is_equal(Node<T>* node)
  {
    unsigned int node_depth = node->get_depth();
    T node_key = node->get_key();

    if(depth != node_depth || key != node_key)
      return false;

    Node<T>* parent_node = node->get_parent();
    if(!(parent == parent_node)) // pointer comparison
      return false;

    if(!this->equal_children(node))
      return false;

    return true;
  }

  bool operator==(Node<T> node)
  {
    return this->is_equal(&node);
  }

  bool has_child(Node<T>* node)
  {
    // implemet a more efficient search (BINARY SEARCH)
    unsigned int node_depth = node->get_depth();
    if(node_depth != depth+1)
      return false;

    for(Node<T>* child : children)
      if(child == node) //pointer comparison
        return true;

    return false;
  }

  friend ostream& operator<<(ostream& out, Node<T>* node)
  {
    unsigned int depth = node->get_depth();
    T key = node->get_key();
    string tab = repeat("\t", depth);

    out << tab << key << endl;
    //tab += "\t";
    for(Node<T>* child: node->get_children())
      {
        if(child != nullptr)
          out << child;
      }
    return out;
  }
};

#endif //_NODE_H
