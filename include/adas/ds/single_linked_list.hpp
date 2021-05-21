/*
 * Single Linked List template data structure
 *
 * Status: DEBUGGED - date May 21 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _SLLIST_H
#define _SLLIST_H

#include <iostream>
#include <iterator>
#include <cstddef>
#include <vector>

#include "../exceptions/general.hpp"
#include "../utilities/print.hpp"
namespace au = adas::utilities;

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
      iterator& get_this(){return *this;}
      iterator& operator+(unsigned int steps)
      {
        try
          {
            SLNode<T>* tmp_node = node;
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

      friend iterator& next(iterator itr){return itr+1;}
      friend iterator& prev(iterator itr)
      {
        pointer node = itr->get_node();
        pointer prev2node = itr->get_prev_node();
        if(prev2node() == nullptr) // itr = head
          {
            SLNode<T>* prev2head = new SLNode<T>();
            prev2head->set_next(node); //node == head node
            return iterator(prev2head).get_this();
          }
        else
          return iterator(prev2node).get_this();
      };

      friend bool operator==(const iterator& a, const iterator& b){return a.node == b.node;}
      friend bool operator!=(const iterator& a, const iterator& b){return a.node != b.node;}

    private:
      pointer node;
    };


    SLList(): size{0}, head{nullptr}, tail{nullptr} {}
    SLList(unsigned int list_size, T default_key);
    SLList(unsigned int list_size);
    SLList(std::initializer_list<T> keys);
    SLList(std::vector<T> keys);

    SLList<T>::iterator begin(){return iterator(head);}
    SLList<T>::iterator end();

    // methods to manipulate SLList<T> data structure
    static void interchange_keys(SLList<T>::iterator node, SLList<T>::iterator other_node);
    SLList<T>::iterator set_key(SLList<T>::iterator position, T node_key);
    SLNode<T>* get_head(){return head;}
    SLNode<T>* get_tail(){return tail;}
    unsigned int get_size(){return size;}
    SLList<T>::iterator get_prev(iterator position);
    SLNode<T>* get_prev_node(SLList<T>::iterator position);
    SLList<T>::iterator insert(SLList<T>::iterator position, T key);
    void erase(SLList<T>::iterator position);
    void push_back(SLNode<T>* node);
    void push_front(SLNode<T>* node);
    void push_back(T node_key);
    void push_front(T node_key);
    void pop_front();
    void pop_back();


    // sort methods
    static void bubble(SLList<T>::iterator first, SLList<T>::iterator last, bool verbose = false);
    static void selection(SLList<T>::iterator first, SLList<T>::iterator last, bool verbose = false);

    // search methods

  };

  /*
   * SLList<T> implementation
   */

  template<class T>
  SLList<T>::SLList(unsigned int list_size, T default_key)
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

  template<class T>
  SLList<T>::SLList(unsigned int list_size)
  /*
   * Create a list of size list_size with 0 as node's key
   */
  {
    SLList(list_size, 0);
  }

  template<class T>
  SLList<T>::SLList(std::initializer_list<T> keys)
    :SLList<T>()
  {
    for(T key : keys)
      this->push_back(key);
  }

  template<class T>
  SLList<T>::SLList(std::vector<T> keys)
    :SLList<T>()
  {
    for(T key : keys)
      this->push_back(key);
  }

  template<class T>
  SLList<T>::iterator SLList<T>::end(){
    SLNode<T>* next2tail = new SLNode<T>();
    tail->set_next(next2tail);
    //next2tail->set_prev(tail);
    return SLList<T>::iterator(next2tail);
  }


  template<class T>
  void SLList<T>::interchange_keys(SLList<T>::iterator node, SLList<T>::iterator other_node)
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
  SLList<T>::iterator SLList<T>::set_key(SLList<T>::iterator position, T node_key)
  {
    SLNode<T>* node = position->get_node();
    node->set_key(node_key);
    return position;
  }

  template<class T>
  SLList<T>::iterator SLList<T>::get_prev(iterator position)
  /*
   * return an iterator to the previous node (if there isn't previose node, return end)
   */
  {
    SLList<T>::iterator prev;
    SLList<T>::iterator itr = this->begin();
    SLList<T>::iterator end = this->end();

    while(itr != end)
      {
        prev = itr;
        itr++;
        if(itr == position)
          return prev;
      }

    return end;
  }

  template<class T>
  SLNode<T>* SLList<T>::get_prev_node(SLList<T>::iterator position)
  {
    SLList<T>::iterator prev = this->get_prev(position);
    if(prev != this->end())
      return prev->get_node();
    else
      return nullptr;
  }


  template<class T>
  SLList<T>::iterator SLList<T>::insert(SLList<T>::iterator position, T key)
  /*
   * Insert a SLNode<T> after the suplied position
   */
  {
    SLNode<T>* node = new SLNode<T>(key);

    SLNode<T>* next_node = position->get_node();
    SLNode<T>* prev_node = this->get_prev_node(position);

    if(prev_node == nullptr)
      head = node;
    else
      prev_node->set_next(node);

    node->set_next(next_node);
    size++;

    return position;
  }

  template<class T>
  void SLList<T>::erase(SLList<T>::iterator position)
  {
    SLNode<T>* node = position->get_node();
    T node_key = node->get_key();

    SLList<T>::iterator prev = this->get_prev(position);

    if(prev != this->end()) // position != head
      {
        SLNode<T>* prev2node = prev->get_node();
        SLNode<T>* next2node = node->get_next();

        prev2node->set_next(next2node);
        delete [] node;
        size--;

        if(next2node == nullptr) // node == tail
          tail = prev2node;
      }
    else //position == head
      this->pop_front();
  }

  template<class T>
  void SLList<T>::push_back(SLNode<T>* node)
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

    size++;
  }

  template<class T>
  void SLList<T>::push_front(SLNode<T>* node)
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

    size++;
  }

  template<class T>
  void SLList<T>::push_back(T node_key)
  {
    SLNode<T>* node = new SLNode<T>(node_key);
    this->push_back(node);
  }

  template<class T>
  void SLList<T>::push_front(T node_key)
  {
    SLNode<T>* node = new SLNode<T>(node_key);
    this->push_front(node);
  }

  template<class T>
  void SLList<T>::pop_front()
  /*
   * Delete first element
   */
  {
    SLNode<T>* next2head = head->get_next();
    delete [] head;
    head = next2head;
    size--;
  }

  template<class T>
  void SLList<T>::pop_back()
  /*
   * Delete last element
   */
  {
    SLNode<T>* prev2tail = this->get_prev_node(SLList<T>::iterator(tail));
    prev2tail->set_next(nullptr);
    delete [] tail;
    tail = prev2tail;
    size--;
  }

  // sort methods
  template<class T>
  void SLList<T>::bubble(SLList<T>::iterator first, SLList<T>::iterator last, bool verbose)
  {
    SLList<T>::iterator itr, inner;

    for(itr=first; itr != last; itr++)
      {
        for(inner=itr+1; inner!=last; inner++)
          {
            if(*inner < *itr)
              SLList<T>::interchange_keys(itr, inner);
          }
        if(verbose)
          au::print::to_stdout(first, last, "\n");
      }
  }
}

#endif //_SLLIST_H
