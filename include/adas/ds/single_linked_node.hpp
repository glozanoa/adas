/*
 * Single Linked node template data structure (for implement SLList template class)
 *
 * Status:
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
    SLNode(T node_key): key{node_key}, next{nullptr} {}
    SLNode(T node_key, SLNode<T>* next_node)
      : key{node_key}, next{next_node} {}

    void update_key(T node_key)
    {
      key = node_key;
    }

    void set_next(SLNode<T>* next_node){next = next_node;}
    void set_key(T node_key){key = node_key;}
    SLNode<T>* get_next(){return next;}
    SLNode<T>* get_node(){return this;}
    T get_key(){return key;}

    static bool has_key(SLNode<T>* node, T node_key)
    /*
     * Check if node has a key node_key
     */
    {
      T key = node->get_key();

      return key == node_key;
    }

    static bool has_key(SLNode<T> node, T node_key)
    /*
     * Check if node has a key node_key
     */
    {
      T key = node.get_key();

      return key == node_key;
    }

    bool operator==(SLNode<T> node)
      {
        T node_key = node.get_key();
        SLNode<T>* next_node = node.get_next();

        if(key == node_key && next == next_node)
          return true;
        return false;
      }

    friend ostream& operator<<(ostream& out, SLNode<T> node)
    {
      T node_key = node.get_key();
      SLNode<T>* next_node = node.get_next();

      if(next_node != nullptr)
        {
          T next_node_key = next_node->get_key();

          out << "SLNode(key: " << node_key
              << ", next: " << next_node_key << ")";
        }
      else
        out << "SLNode(key: " << node_key << ", next: NONE)";

      return out;
    }


    friend ostream& operator<<(ostream& out, SLNode<T>* node)
    {
      T node_key = node->get_key();
      SLNode<T>* next_node = node->get_next();

      if(next_node != nullptr)
        {
          T next_node_key = next_node->get_key();

          out << "SLNode(key: " << node_key
              << ", next: " << next_node_key << ")";
        }
      else
        out << "SLNode(key: " << node_key << ", next: NONE)";

      return out;
    }
  };
}

#endif //_SLNODE_H
