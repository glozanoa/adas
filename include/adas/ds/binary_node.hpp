/*
 * BinaryNode template class
 *
 * Debuged class - May 14 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _BINARY_NODE_H
#define _BINARY_NODE_H

#include "node.hpp"

namespace adas::ds
{
  typedef enum NT
    {
      LEFT_NODE,
      RIGHT_NODE,
      NONE
    }NT;

  template<typename T>
  class BinaryNode : public Node<T>
  {
  protected:
    BinaryNode<T>* lchild;
    BinaryNode<T>* rchild;

  public:
    BinaryNode(T key);
    BinaryNode(T key, BinaryNode<T>* parent, NT type);
    BinaryNode(T key, BinaryNode<T>* parent, NT type,
               BinaryNode<T>* lchild_node, BinaryNode<T>* rchild_node);

    // methods to manipulate BinaryNode<T>
    BinaryNode<T>* get_parent(){return (BinaryNode<T>*) this->parent;}
    BinaryNode<T>* get_child(NT type);
    void add_child(BinaryNode<T>* child, NT type);
  };


  /* IMPLEMENTATION BinaryNode<T> class */

  template<class T>
  BinaryNode<T>::BinaryNode(T key)
    :Node<T>(key)
  {
    lchild = nullptr;
    rchild = nullptr;
    this->children = {lchild, rchild};
  }

  template<class T>
  BinaryNode<T>::BinaryNode(T key, BinaryNode<T>* parent, NT type)
    :Node<T>(key)
  {
    lchild = nullptr;
    rchild = nullptr;
    this->children = {lchild, rchild};

    if(parent != nullptr)
      parent->add_child(this, type);
  }

  template<class T>
  BinaryNode<T>::BinaryNode(T key, BinaryNode<T>* parent, NT type,
                            BinaryNode<T>* lchild_node, BinaryNode<T>* rchild_node)
    :BinaryNode<T>(key, parent, type)
  {
    this->add_child(lchild_node, NT::LEFT_NODE);
    this->add_child(rchild_node, NT::RIGHT_NODE);
  }

  template<class T>
  BinaryNode<T>* BinaryNode<T>::get_child(NT type){
    if(type == NT::LEFT_NODE)
      return lchild;
    else if(type == NT::RIGHT_NODE)
      return rchild;
    else
      return nullptr;
  }

  template<class T>
  void BinaryNode<T>::add_child(BinaryNode<T>* child, NT type)
  {
    child->set_depth(this->depth+1);
    child->set_parent(this);

    if(type == NT::LEFT_NODE)
      lchild = child;
    else
      rchild = child;

    this->children = {lchild, rchild};
  }


}

#endif //_BINARY_NODE_H
