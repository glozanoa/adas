/*
 * Double Linked List template data structure
 *
 * Status:
 *
 * Maintiner: glozanoa <glozanoa@uni.pe>
 */

#ifndef _DLLIST_H
#define _DLLIST_H

#include <iostream>


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
    DLNode<T>* head;
    DLNode<T>* tail;
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
      while(list_size > 1)
        {
          DLNode<T>* next_node = new DLNode(default_key);
          node->set_next(next_node);
          next_node->set_prev(node);
          node = next_node;
          list_size--;
        }
      tail = node;
    }

    DLNode<T>* get_head(){return head;}
    DLNode<T>* get_tail(){return tail;}
    unsigned int get_size(){return size;}

    DLList(unsigned int list_size)
    /*
     * Create a list of size list_size with 0 as node's key
     */
    {
      DLList(list_size, 0);
    }

    void push_back(DLNode<T>* node)
    {
      node->only_set_next(nullptr);
      if(tail == nullptr && head == nullptr) // this is a empty list
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

    void push_front(DLNode<T>* node)
    {
      node->only_set_prev(nullptr);
      if(tail == nullptr && head == nullptr) // this is a empty list
        {
          head = node;
          tail = node;
          node->only_set_next(nullptr);
        }
      else
        {
          node->set_next(head);
          head = node;
        }
    }

    void push_back(T node_key)
    {
      DLNode<T>* node = new DLNode<T>(node_key);
      this->push_back(node);
    }

    void push_front(T node_key)
    {
      DLNode<T>* node = new DLNode<T>(node_key);
      this->push_front(node);
    }

    friend ostream& operator<<(ostream& out, DLList<T> list)
    {
      DLNode<T>* node = list.get_head();
      if(node != nullptr)
        {
          while(node->get_next() != nullptr)
            {
              T key = node->get_key();
              out << key << std::endl;
              node = node->get_next();
            }

          DLNode<T>* tail = list.get_tail();
          out << tail->get_key();
        }

      return out;
    }
  };
}

#endif //_DLLIST_H
