/*
 * Node Template class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _NODE_H
#define _NODE_H

#include <list>
using namespace std;


#include "exceptions/node.hpp"

template<typename T>
class Node
{
protected:
  T data;
  unsigned int depth;
  Node<T>* parent;
  list<Node<T>*> children;

public:
  Node(T data): data{data}, parent{nullptr}, depth{0} {}
  Node(T data, Node<T>* parent): data{data}, parent{parent}, depth{0} {}
  Node(T data, Node<T>* parent, list<Node<T>*> children)
    : data{data}, parent{parent}, depth{0}, children{children}{}



  T get_data(){return data;}
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

  friend ostream& operator<<(ostream& out, Node<T>* node)
  {
    unsigned int depth = node->get_depth();
    T data = node->get_data();
    string tab = repeat("\t", depth);

    out << tab << data << endl;
    tab += "\t";
    for(Node<T>* child: node->get_children())
      {
        if(child != nullptr)
          out << tab << child;
      }
    return out;
  }
};

#endif //_NODE_H
