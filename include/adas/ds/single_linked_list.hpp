/*
 * Single Linked List template data structure
 *
 * Status:
 *
 * Maintiner: glozanoa <glozanoa@uni.pe>
 */

#ifndef _SLLIST_H
#define _SLLIST_H

#include "single_linked_node.hpp"
using namespace adas::ds;

namespace adas::ds
{
  template<class T>
  class SLList
  /*
   * SLList : Single Linked List
   */
  {
  protected:
    SLNode<T>* head;
    SLNode<T>* tail;
    unsigned int size;
  public:
    SLList(): size{0}, head{nullptr}, tail{nullptr} {}
    SLList(unsigned int list_size, T default_key)
    /*
     * Create a list of size list_size with default_key as node's key
     */
    {
      head = new SLNode(default_key);
      SLNode<T>* itr = head;
      while(list_size > 0)
        {
          SLNode<T>* next_node = new SLNode(default_key);
          itr.set_next(next_node);
          itr = next_node;
          list_size--;
        }
      tail = itr;
    }

    SLList(unsigned int list_size)
    /*
     * Create a list of size list_size with 0 as node's key
     */
    {
      SLList(list_size, 0);
    }

    void push_back(SLNode<T>* node)
    {
      node->set_next(nullptr);
      if(tail == nullptr && head = nullptr) // this is a empty list
        {
          head = node;
          tail = node;
        }
      else
        {
          tail->set_next(node);
          tail = node;
        }
    }

    void push_front(SLNode<T>* node)
    {
      node->set_next(head);
      head = node;
    }


  };
}

#endif //_SLLIST_H
