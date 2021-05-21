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
#include <iterator>
#include <vector>
#include <initializer_list>

#include "../exceptions/general.hpp"
#include "../utilities/print.hpp"
namespace au = adas::utilities;

#include "../algorithm/search/serial.hpp"
namespace ases = adas::algorithm::search::serial;

#include "doubly_linked_node.hpp"
using namespace adas::ds;

namespace adas::ds
{
  template<class T>
  class DLList
  /*
   * DLList : Doubly Linked List
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
      iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }
      // TLMGLA
      iterator& get_this(){return *this;}
      iterator& operator+(unsigned int steps)
      {
        try
          {
            DLNode<T>* tmp_node = node;
            while(steps > 0)
              {
                tmp_node = tmp_node->get_next();
                if(tmp_node == nullptr)
                  throw out_of_range("node is nullptr");

                steps--;
              }
            return iterator(tmp_node).get_this();
          }
        catch(exception& error)
          {
            std::cout << error.what() << endl;
            exit(EXIT_FAILURE);
          }
      }
      iterator& operator-(unsigned int steps)
      {
        try
          {
            DLNode<T>* tmp_node = node;
            while(steps > 0)
              {
                tmp_node = tmp_node->get_prev();
                if(tmp_node == nullptr)
                  throw out_of_range("node is nullptr");

                steps--;
              }
            return iterator(tmp_node).get_this();
          }
        catch(exception& error)
          {
            std::cout << error.what() << endl;
            exit(EXIT_FAILURE);
          }
      }

      friend iterator& next(iterator itr){return itr+1;}
      friend iterator& prev(iterator itr)
      {
        pointer node = itr->get_node();
        if(itr->get_prev() == nullptr) // itr = head
          {
            DLNode<T>* prev2head = new DLNode<T>();
            prev2head->set_next(itr->get_node());
            return iterator(prev2head).get_this();
          }
        else
          return itr-1;
      };

      friend bool operator==(const iterator& a, const iterator& b){return a.node == b.node;}
      friend bool operator!=(const iterator& a, const iterator& b){return a.node != b.node;}

    private:
      pointer node;
    };


    DLList(): size{0}, head{nullptr}, tail{nullptr} {}
    DLList(unsigned int list_size, T default_key);
    DLList(unsigned int list_size) :DLList(list_size, 0) {}
    DLList(std::initializer_list<T> keys);
    DLList(std::vector<T> keys);
    //~DLList();

    DLList<T>::iterator begin();
    DLList<T>::iterator end(); // return a iterator to a node next to tail

    DLNode<T>* get_head(){return head;}
    DLNode<T>* get_tail(){return tail;}
    unsigned int get_size(){return size;}

    // methods to manipulate DLList<T> data structure
    static void copy_key(DLList<T>::iterator node, DLList<T>::iterator other);
    static void interchange_keys(DLList<T>::iterator node, DLList<T>::iterator other_node);
    DLList<T>::iterator insert(DLList<T>::iterator position, T key);
    DLList<T>::iterator set_key(DLList<T>::iterator position, T node_key);
    void erase(DLList<T>::iterator position);
    void push_back(DLNode<T>* node);
    void push_front(DLNode<T>* node);
    void push_back(T node_key);
    void push_front(T node_key);
    void pop_front();
    void pop_back();

    // sort methods
    static void bubble(DLList<T>::iterator first, DLList<T>::iterator last, bool verbose = false);
    static void bibubble(DLList<T>::iterator first, DLList<T>::iterator last, bool verbose = false);
    static void selection(DLList<T>::iterator first, DLList<T>::iterator last, bool verbose = false);
    static void insertion(DLList<T>::iterator first, DLList<T>::iterator last, bool verbose = false);

    // search methods
  };




  /*
   * Implementation of DLList<T> class
   */

  template<class T>
  DLList<T>::DLList(unsigned int list_size, T default_key)
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

  template<class T>
  DLList<T>::DLList(std::initializer_list<T> keys)
    :DLList<T>()
  {
    for(T key : keys)
      this->push_back(key);
  }


  template<class T>
  DLList<T>::DLList(std::vector<T> keys)
    :DLList<T>()
  {
    for(T key : keys)
      this->push_back(key);
  }

  template<class T>
  DLList<T>::iterator DLList<T>::begin()
  {
    return DLList<T>::iterator(head);
  }

  template<class T>
  DLList<T>::iterator DLList<T>::end(){
    DLNode<T>* next2tail = new DLNode<T>();
    tail->set_next(next2tail);
    //next2tail->set_prev(tail);
    return DLList<T>::iterator(next2tail);
  }

  template<class T>
  DLList<T>::iterator DLList<T>::set_key(DLList<T>::iterator position, T node_key)
  {
    DLNode<T>* node = position->get_node();
    node->set_key(node_key);
    return position;
  }

  template<class T>
  void DLList<T>::copy_key(DLList<T>::iterator node, DLList<T>::iterator other)
  /*
   * Copy key of 'other' node to 'node'
   */
  {
    T other_key = other->get_key();
    node->set_key(other_key);
  }


  template<class T>
  void DLList<T>::interchange_keys(DLList<T>::iterator node, DLList<T>::iterator other_node)
  /*
   * Interchange keys of 2 nodes (pointed by iterators)
   */
  {
    T node_key = node->get_key();
    T other_key = other_node->get_key();

    node->set_key(other_key);
    other_node->set_key(node_key);
  }

  template<class T>
  DLList<T>::iterator DLList<T>::insert(DLList<T>::iterator position, T key)
  /*
   * Insert a DLNode<T> in the suplied position
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

  template<class T>
  void DLList<T>::erase(DLList<T>::iterator position)
  {
    DLNode<T>* node = position->get_node();
    DLNode<T>* prev2node = node->get_prev();
    DLNode<T>* next2node = node->get_next();

    if(next2node == nullptr) // node == tail
      {
        prev2node->only_set_next(nullptr);
        tail = prev2node;
      }
    else
      prev2node->set_next(next2node);

    delete [] node;
    size--;
  }

  template<class T>
  void DLList<T>::push_back(DLNode<T>* node)
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

  template<class T>
  void DLList<T>::push_front(DLNode<T>* node)
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

  template<class T>
  void DLList<T>::push_back(T node_key)
  {
    DLNode<T>* node = new DLNode<T>(node_key);
    this->push_back(node);
  }

  template<class T>
  void DLList<T>::push_front(T node_key)
  {
    DLNode<T>* node = new DLNode<T>(node_key);
    this->push_front(node);
  }

  template<class T>
  void DLList<T>::pop_front()
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

  template<class T>
  void DLList<T>::pop_back()
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

  /*
   * Implementation of Sort methods
   */

  template<class T>
  void DLList<T>::bubble(DLList<T>::iterator first, DLList<T>::iterator last, bool verbose)
  {
    DLList<T>::iterator itr, inner;

    for(itr=first; itr != last; itr++)
      {
        for(inner=itr+1; inner!=last; inner++)
          {
            if(*inner < *itr)
              DLList<T>::interchange_keys(itr, inner);
          }
        if(verbose)
          au::print::to_stdout(first, last, "\n");
      }
  }

  template<class T>
  void DLList<T>::bibubble(DLList<T>::iterator first, DLList<T>::iterator last, bool verbose)
  {

    DLList<T>::iterator init = prev(first);
    DLList<T>::iterator end = last;

    DLList<T>::iterator itr; // iterator to iterate in bidirectional data structure
    DLList<T>::iterator aux; // auxiliary iterator to store maximum and minimum element


    while(init != end)
      {
        itr=init;
        aux = init;
        while(++itr != end)
          {
            if(*itr < *aux) // aux = max
              DLList<T>::interchange_keys(aux, itr);
            aux = itr;
          }

        if(--end == init)
          break;

        itr = end;
        aux = end;

        while(--itr != init)
          {
            if(*aux < *itr) // aux = min
              DLList<T>::interchange_keys(aux, itr);
            aux = itr;
          }
        init++;

        if(verbose)
          au::print::to_stdout(first, last, "\n");
      }
  }


  template<class T>
  void DLList<T>::selection(DLList<T>::iterator first, DLList<T>::iterator last, bool verbose)
  {
    DLList<T>::iterator itr, min;
    for(itr=first; itr != last-1; itr++)
      {
        if(verbose)
          au::print::to_stdout(first, last, "\n");

        min = ases::min_element(itr+1, last);
        if(*min  < *itr)
          DLList<T>::interchange_keys(itr, min);
      }
  }

  template<class T>
  void DLList<T>::insertion(DLList<T>::iterator first, DLList<T>::iterator last, bool verbose)
  {
    DLList<T>::iterator prev2first = prev(first);
    DLList<T>::iterator itr, inner;

    for(itr=first+1; itr != last; itr++)
      {
        T key = itr->get_key();
        inner = prev(itr);
        while(inner != prev2first && key < inner->get_key())
          {
            DLList<T>::copy_key(next(inner), inner);
            inner--;
          }
        next(inner)->set_key(key);

        if (verbose)
          au::print::to_stdout(first, last, "\n");
      }
  }
}

#endif //_DLLIST_H
