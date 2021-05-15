/*
 * Single Linked node template data structure (for implement SLList template class)
 *
 * Status:
 *
 * Maintiner: glozanoa <glozanoa@uni.pe>
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
    void update_key(T node_key)
    {
      key = node_key;
    }

    void set_next(SLNode<T> next_node){next = next_node;}
    void set_key(T node_key){key = node_key;}
    SLNode<T>* get_next(){return next;}
    T get_key(){return key;}

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
      out << "SLNode(key: " << node.get_key() << ", next: " << node.get_next() << ")" << endl;
      return out;
    }
  };
}

#endif //_SLNODE_H
