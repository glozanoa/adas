/*
 * Single Linked List template data structure
 *
 * Status:
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _SLLIST_H
#define _SLLIST_H

#include <iostream>
#include <iterator>
#include <cstddef>

#include "single_linked_node.hpp"
using namespace adas::ds;

#include "../algorithm/search/serial.hpp"
namespace ases = adas::algorithm::search::serial;

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
      iterator operator++(int){iterator tmp = *this; ++(*this); return tmp;}
      iterator& operator+(unsigned int steps)
      {
        try
          {
            while(steps > 0)
              {
                node = node->get_next();
                if(node == nullptr)
                  throw out_of_range("node is nullptr");
                  steps--;
              }
            return *this;
          }
        catch(exception& error)
          {
            std::cout << error.what() << endl;
            exit(EXIT_FAILURE);
          }
      }
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
    SLNode<T>* get_node(){return this;}
    unsigned int get_size(){return size;}

    iterator set_key(iterator position, T node_key)
    {
      SLNode<T>* node = position->get_node();
      node->set_key(node_key);
      return position;
    }

    // iterator insert(iterator position, T key)
    // /*
    //  * Insert a SLNode<T> after the suplied position
    //  */
    // {
    //   SLNode<T>* node = new SLNode<T>(key);

    //   SLNode<T>* prev_node = position->get_node();
    //   SLNode<T>* next_node = prev_node->get_next();

    //   prev_node->set_next(node);
    //   node->set_next(next_node);

    //   if(next_node == nullptr)
    //     tail = node;

    //   return position;
    // }


    // void erase(iterator position)
    // {
    //   SLNode<T>* node = position->get_node();
    //   T node_key = node->get_key();
    //   typename SLList<T>::iterator prev = ases::search_prev(this->begin(), this->end(),
    //                                                         SLNode<T>::has_key, node_key);
    //   if(prev != this->end())
    //     {
    //       SLNode<T>* prev2node = prev->get_node();
    //       SLNode<T>* next2node = node->get_next();

    //       prev2node->set_next(next2node);
    //       delete [] node;

    //       if(next2node == nullptr) // node == tail
    //         tail = prev2node;
    //     }
    //   else //in this case position == head
    //     this->pop_front();
    // }


    void push_back(SLNode<T>* node)
    {
      node->set_next(nullptr);
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

    void push_front(SLNode<T>* node)
    {
      if(tail == nullptr && head == nullptr) // this is a empty list
        {
          head = node;
          tail = node;
          node->set_next(nullptr);
        }
      else
        {
          node->set_next(head);
          head = node;
        }
    }

    void push_back(T node_key)
    {
      SLNode<T>* node = new SLNode<T>(node_key);
      this->push_back(node);
    }

    void push_front(T node_key)
    {
      SLNode<T>* node = new SLNode<T>(node_key);
      this->push_front(node);
    }

    void pop_front()
    /*
     * Delete first element
     */
    {
      SLNode<T>* next2head = head->get_next();
      delete [] head;
      head = next2head;
    }

    // void pop_back()
    // /*
    //  * Delete last element
    //  */
    // {
    //   SLNode<T>* prev2tail = tail->get_prev();
    //   prev2tail->set_next(nullptr);
    //   delete [] tail;
    //   tail = prev2tail;
    // }
  };
}

#endif //_SLLIST_H
