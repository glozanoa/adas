/*
 * BinaryNode template class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _BINARY_NODE_H
#define _BINARY_NODE_H

#include "node.hpp"

typedef enum NT
  {
    LEFT_NODE,
    RIGHT_NODE
  }NT;

template<typename T>
class BinaryNode : public Node<T>
{
protected:
  BinaryNode<T>* lchild;
  BinaryNode<T>* rchild;

public:
  BinaryNode(T key)
    :Node<T>(key)
  {
    lchild = nullptr;
    rchild = nullptr;
    this->children = {lchild, rchild};
  }

  BinaryNode(T key, BinaryNode<T>* parent, NT type)
    :Node<T>(key)
  {
    lchild = nullptr;
    rchild = nullptr;
    this->children = {lchild, rchild};

    if(parent != nullptr)
      {
        parent->add_child(this, type);
        this->parent = parent;
      }
  }

  BinaryNode(T key, BinaryNode<T>* parent, NT type,
             BinaryNode<T>* lchild_node, BinaryNode<T>* rchild_node)
    :BinaryNode<T>(key, parent, type)
  {
    lchild = lchild_node;
    rchild = rchild_node;
    this->children = {lchild, rchild};
  }


  BinaryNode<T>* get_parent(){return (BinaryNode<T>*) this->parent;}
  BinaryNode<T>* get_lchild(){return lchild;}
  BinaryNode<T>* get_rchild(){return rchild;}

  void add_child(BinaryNode<T>* child, NT type)
  {
    child->set_depth(this->depth+1);
    child->set_parent(this);

    if(type == NT::LEFT_NODE)
      lchild = child;
    else
      rchild = child;

    this->children = {lchild, rchild};
  }
};

#endif //_BINARY_NODE_H
