/*
 * Single Linked node template data structure (for implement SLList template class)
 *
 * Status: TESTED - date Jul 29 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _SLNODE_H
#define _SLNODE_H

namespace adas::ds
{
  template<class T>
  class SLNode
  /*
   * SLNode : Single Linked Node
   */
  {
  protected:
    T key;
    SLNode<T>* next;

  public:
    SLNode(): next{nullptr} {}
    SLNode(T node_key): key{node_key}, next{nullptr} {}
    SLNode(T node_key, SLNode<T>* next_node): key{node_key}, next{next_node} {}

    // method to manipulate SLNode<T> objects
    void set_next(SLNode<T>* next_node){next = next_node;}
    void set_key(T node_key){key = node_key;}
    SLNode<T>* get_next(){return next;}
    SLNode<T>* get_node(){return this;}
    T get_key(){return key;}
    bool has_key(T node_key);
    bool operator<(SLNode<T> node);
    bool operator==(SLNode<T> node);

    template<class L>
    friend ostream& operator<<(ostream& out, SLNode<L> node);
  };

  /*
   * Class implementation
   */

  template<class T>
  bool SLNode<T>::has_key(T node_key)
  /*
   * Check if node has a key node_key
   */
  {
    return key == node_key;
  }

  template<class T>
  bool SLNode<T>::operator<(SLNode<T> node)
  {
    T node_key = node.get_key();
    return key < node_key;
  }

  template<class T>
  bool SLNode<T>::operator==(SLNode<T> node)
  {
    T node_key = node.get_key();
    SLNode<T>* next_node = node.get_next();

    if(key == node_key && next == next_node)
      return true;
    return false;
  }

  template<class T>
  ostream& operator<<(ostream& out, SLNode<T> node)
  {
    T node_key = node.get_key();
    SLNode<T>* next_node = node.get_next();

    if(next_node != nullptr)
      {
        out << "SLNode(key: " << node_key
            << ", next: " << next_node << ")";
      }
    else
      out << "SLNode(key: " << node_key << ", next: NONE)";

    return out;
  }

} //  adas::ds

#endif //_SLNODE_H