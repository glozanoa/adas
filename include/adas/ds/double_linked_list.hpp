/*
 * Double Linked List template data structure
 *
 * Status:
 *
 * Maintiner: glozanoa <glozanoa@uni.pe>
 */

#ifndef _DLLIST_H
#define _DLLIST_H

#include "double_linked_node.hpp"
using namespace adas::ds;

namespace adas::ds
{
  template<class T>
  class DLList
  /*
   * DLList : Double Linked List
   */
  {
  protected:
    SLNode<T>* head;
    SLNode<T>* tail;
    unsigned int size;
  public:
    DLList(): size{0}, head{nullptr}, tail{nullptr} {}
    DLList(unsigned int list_size, T default_key)
    /*
     * Create a list of size list_size with default_key as node's key
     */
      :size{list_size}
    {
      head = new DLNode(default_key);
      DLNode<T>* node = new DLNode(default_key);
      node->set_prev(head);
      list_size--;
      while(list_size > 0)
        {
          DLNode<T>* next_node = new SLNode(default_key);
          node->set_next(next_node);
          next_node->set_prev(node);
          node = next_node;
          list_size--;
        }
      tail = node;
    }

    DLList(unsigned int list_size)
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
          node->set_prev(tail);
          tail = node;
        }
    }

    void push_front(SLNode<T>* node)
    {
      node->set_next(head);
      node->set_prev(nullptr);
      head = node;
    }
  };
}

#endif //_DLLIST_H
