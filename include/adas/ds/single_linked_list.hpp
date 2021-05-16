/*
 * Single Linked List template data structure
 *
 * Status:
 *
 * Maintiner: glozanoa <glozanoa@uni.pe>
 */

#ifndef _SLLIST_H
#define _SLLIST_H

#include <iostream>
#include <iterator>
#include <cstddef>

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


    struct iterator
    {
      using iterator_category = std::forward_iterator_tag;
      using value_type        = T;
      using difference_type   = std::ptrdiff_t;
      using pointer           = SLNode<T>*;
      using reference         = SLNode<T>&;

      iterator() :node{nullptr} {}
      iterator(pointer node) :node{node} {}
      reference operator*() const {return *node;}
      pointer operator->(){return node;}
      iterator& operator++(){node = node->get_next(); return *this;}
      iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
      friend bool operator==(const iterator& a, const iterator& b){return a.node == b.node;}
      friend bool operator!=(const iterator& a, const iterator& b){return a.node != b.node;}

    private:
      pointer node;
    };


    SLList(): size{0}, head{nullptr}, tail{nullptr} {}
    SLList(unsigned int list_size, T default_key)
    /*
     * Create a list of size list_size with default_key as node's key
     */
      :size{list_size}
    {
      head = new SLNode(default_key);
      SLNode<T>* node = head;
      while(list_size > 0)
        {
          SLNode<T>* next_node = new SLNode(default_key);
          node->set_next(next_node);
          node = next_node;
          list_size--;
        }
      tail = node;
    }

    SLList(unsigned int list_size)
    /*
     * Create a list of size list_size with 0 as node's key
     */
    {
      SLList(list_size, 0);
    }


    iterator begin(){return iterator(head);}
    iterator end(){return iterator(tail->get_next());}

    SLNode<T>* get_head(){return head;}
    SLNode<T>* get_tail(){return tail;}
    unsigned int get_size(){return size;}

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

    friend ostream& operator<<(ostream& out, SLList<T> list)
    {
      SLNode<T>* node = list.get_head();

      while(node->get_next() != nullptr)
        {
          T key = node->get_key();
          out << key << std::endl;
          node = node->get_next();
        }

      SLNode<T>* tail = list.get_tail();
      out << tail->get_key();

      return out;
    }

  };
}

#endif //_SLLIST_H
