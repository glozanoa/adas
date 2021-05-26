/*
 * Double Linked node data structure (for implementing DLList<T> class)
 *
 * Status: DEBUGGED - date: May 21 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _DLNODE_H
#define _DLNODE_H

namespace adas::ds
{

  typedef enum DLNT
    {
      NEXT_NODE,
      PREV_NODE,
    }DLNT;

  template<class T>
  class DLNode
  /*
   * DLNode : Doubly Linked Node
   */
  {
  protected:
    T key;
    DLNode<T>* next;
    DLNode<T>* prev;
  public:
    DLNode() :prev{nullptr}, next{nullptr} {}
    DLNode(T node_key): key{node_key}, prev{nullptr}, next{nullptr} {}
    DLNode(T node_key, DLNode<T>* node, DLNT node_type);
    DLNode(T node_key, DLNode<T>* prev_node, DLNode<T>* next_node);

    //methods to manipulate DLNode<T> class
    void only_set_next(DLNode<T>* next_node){next = next_node;}
    void only_set_prev(DLNode<T>* prev_node){prev = prev_node;}
    void set_next(DLNode<T>* next_node);
    void set_prev(DLNode<T>* prev_node);
    void set_key(T node_key){key = node_key;}
    bool has_key(T key);
    DLNode<T>* get_node(){return this;}
    DLNode<T>* get_next(){return next;}
    DLNode<T>* get_prev(){return prev;}
    T get_key(){return key;}
    bool operator<(DLNode<T> node);
    bool operator==(DLNode<T> node);

    // T2LMGLA
    template<class L>
    friend ostream& operator<<(ostream& out, DLNode<L>* node);

    template<class L>
    friend ostream& operator<<(ostream& out, DLNode<L> node);
  };


  /*
   * DLNode<T> implementation
   */

  template<class T>
  DLNode<T>::DLNode(T node_key, DLNode<T>* node, DLNT node_type)
    : key{node_key}
  {
    if(node_type == DLNT::NEXT_NODE)
      next = node;
    else
      prev = node;
  }

  template<class T>
  DLNode<T>::DLNode(T node_key, DLNode<T>* prev_node, DLNode<T>* next_node)
    : key{node_key}, prev{prev_node}, next{next_node} {}

  template<class T>
  void DLNode<T>::set_next(DLNode<T>* next_node)
  {
    next = next_node;
    next_node->only_set_prev(this);
  }

  template<class T>
  void DLNode<T>::set_prev(DLNode<T>* prev_node)
  {
    prev = prev_node;
    prev_node->only_set_next(this);
  }

  template<class T>
  bool DLNode<T>::has_key(T node_key)
  /*
   * Check if node has a key node_key
   */
  {
    return key == node_key;
  }

  template<class T>
  bool DLNode<T>::operator<(DLNode<T> node)
  {
    T node_key = node.get_key();
    return key < node_key;
  }

  template<class T>
  bool DLNode<T>::operator==(DLNode<T> node)
  {
    T node_key = node.get_key();
    DLNode<T>* next_node = node.get_next();
    DLNode<T>* prev_node = node.get_prev();

    if(key == node_key &&
       next == next_node && prev == prev_node)
      return true;
    return false;
  }

  template<typename T>
  ostream& operator<<(ostream& out, DLNode<T>* node)
    {
      T node_key = node->get_key();
      DLNode<T>* prev_node = node->get_prev();
      DLNode<T>* next_node = node->get_next();

      if(next_node != nullptr && prev_node != nullptr)
        {
          T prev_node_key = prev_node->get_key();
          T next_node_key = next_node->get_key();

          out << "DLNode(key: " << node_key
              << ", prev: " << prev_node_key
              << ", next: " << next_node_key << ")";
        }
      else if(next_node != nullptr)
        {
          T next_node_key = next_node->get_key();

          out << "DLNode(key: " << node_key
              << ", prev: NONE"
              << ", next: " << next_node_key << ")";
        }
      else if (prev_node != nullptr)
        {
          T prev_node_key = prev_node->get_key();

          out << "DLNode(key: " << node_key
              << ", prev: " << prev_node_key
              << ", next: NONE)";
        }
      else
        out << "DLNode(key: " << node_key << ", prev: NONE , next: NONE)";


      return out;
    }

  template<typename T>
  ostream& operator<<(ostream& out, DLNode<T> node)
    {
      T node_key = node.get_key();
      DLNode<T>* prev_node = node.get_prev();
      DLNode<T>* next_node = node.get_next();

      if(next_node != nullptr && prev_node != nullptr)
        {
          T prev_node_key = prev_node->get_key();
          T next_node_key = next_node->get_key();

          out << "DLNode(key: " << node_key
              << ", prev: " << prev_node_key
              << ", next: " << next_node_key << ")";
        }
      else if(next_node != nullptr)
        {
          T next_node_key = next_node->get_key();

          out << "DLNode(key: " << node_key
              << ", prev: NONE"
              << ", next: " << next_node_key << ")";
        }
      else if (prev_node != nullptr)
        {
          T prev_node_key = prev_node->get_key();

          out << "DLNode(key: " << node_key
              << ", prev: " << prev_node_key
              << ", next: NONE)";
        }
      else
        out << "DLNode(key: " << node_key << ", prev: NONE , next: NONE)";


      return out;
    }

}

#endif //_DLNODE_H
