/*
 * Double Linked List template data structure
 *
 * Status: DEBUGGED - date: May 16 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _DLLIST_H
#define _DLLIST_H

#include <iostream>

#include "../exceptions/general.hpp"

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

    struct iterator
    {
      using iterator_category = std::bidirectional_iterator_tag;
      using value_type        = T;
      using difference_type   = std::ptrdiff_t;
      using pointer           = DLNode<T>*;
      using reference         = DLNode<T>&;

      iterator() :node{nullptr} {}
      iterator(pointer node) :node{node} {}
      reference operator*() const {return *node;}
      pointer operator->(){return node;}
      iterator& operator--(){node = node->get_prev(); return *this;}
      iterator& operator++(){node = node->get_next(); return *this;}
      iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }
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

    DLList(unsigned int list_size)
    /*
     * Create a list of size list_size with 0 as node's key
     */
    {
      DLList(list_size, 0);
    }

    DLList<T>::iterator begin(){return DLList<T>::iterator(head);}
    DLList<T>::iterator end(){return DLList<T>::iterator(tail->get_next());}

    DLList<T>::iterator set_key(DLList<T>::iterator position, T node_key)
    {
      DLNode<T>* node = position->get_node();
      node->set_key(node_key);
      return position;
    }


    DLNode<T>* get_head(){return head;}
    DLNode<T>* get_tail(){return tail;}
    unsigned int get_size(){return size;}


    DLList<T>::iterator insert(DLList<T>::iterator position, T key)
    /*
     * Insert a DLNode<T> after the suplied position
     */
    {
      DLNode<T>* node = new DLNode<T>(key);

      DLNode<T>* next_node = position->get_node();
      DLNode<T>* prev_node = next_node->get_prev();


      node->set_next(next_node);
      if(prev_node != nullptr)
        node->set_prev(prev_node);
      else // position == head -> prev_node == nullptr
        {
          node->only_set_prev(nullptr);
          head = node;
        }

      size++;

      return position;
    }

    void erase(DLList<T>::iterator position)
    {
      DLNode<T>* node = position->get_node();
      DLNode<T>* prev2node = node->get_prev();
      DLNode<T>* next2node = node->get_next();

      if(next2node == nullptr) // node == tail
        {
          prev2node->only_set_next(nullptr);
          tail = prev2node;
          delete [] node;
        }
      else
        {
          prev2node->set_next(next2node);
          delete [] node;
        }
      size--;
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

      size++;
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

      size++;
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

    void pop_front()
    /*
     * Delete first element
     */
    {
      DLNode<T>* next2head = head->get_next();
      next2head->only_set_prev(nullptr);
      delete [] head;
      head = next2head;
      size--;
    }

    void pop_back()
    /*
     * Delete last element
     */
    {
      DLNode<T>* prev2tail = tail->get_prev();
      prev2tail->only_set_next(nullptr);
      delete [] tail;
      tail = prev2tail;
      size--;
    }
  };
}

#endif //_DLLIST_H
