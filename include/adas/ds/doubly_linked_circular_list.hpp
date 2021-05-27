/*
 * Double Linked Circular List template data structure
 *
 * Status: DEBUGGED - date: May 27 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _DLCLIST_H
#define _DLCLIST_H

#include <iostream>
#include <iterator>
#include <vector>
#include <initializer_list>


#include "../exceptions/general.hpp"

#include "../utilities/print.hpp"
namespace au = adas::utilities;

#include "doubly_linked_list.hpp"
#include "doubly_linked_node.hpp"
using namespace adas::ds;

namespace adas::ds
{

  template<class T>
  class DLCList : public DLList<T>
  /*
   * DLCList : Doubly Linked Circular List
   */
  {
  public:
    DLCList();
    DLCList(std::initializer_list<T> keys);


    // Methods to manipulate DLCList<T>
    DLNode<T>* get_head(){return this->head;}
    void push_back(DLNode<T>* node);
    void push_back(T key);

    template<class L>
    friend ostream& operator<<(ostream& out, DLCList<L> list);
  };

  template<class T>
  DLCList<T>::DLCList()
  {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
    this->next2tail =nullptr; // node to generate "end" iterator
  }

  template<class T>
  DLCList<T>::DLCList(std::initializer_list<T> keys)
    :DLCList<T>()
  {
    for(T key : keys)
      this->push_back(key);
  }

  template<class T>
  void DLCList<T>::push_back(DLNode<T>* node)
  {
    if(this->tail == nullptr && this->head == nullptr) // this is a empty list
      {
        this->head = node;
        this->tail = node;
      }
    else
      {
        this->tail->set_next(node);
        this->tail = node;
      }

    this->tail->set_next(this->head);
    this->size++;
  }

  template<class T>
  void DLCList<T>::push_back(T key)
  {
    DLNode<T>* node = new DLNode<T>(key);
    this->push_back(node);
  }

  template<class T>
  ostream& operator<<(ostream& out, DLCList<T> list)
  {
    unsigned int counter = 0; //count how many time the head node is printed

    DLNode<T>* head = list.get_head();
    typename DLList<T>::iterator itr = list.begin();
    while (counter < 2) // if counter == 2, then we have printed all element of cricular list
      {
        DLNode<T>* node = itr->get_node();
        out << node << endl;
        if(node == head)
          counter++;

        itr++;
      }

    return out;
  }


} // end namespace adas::ds


#endif //_DLCLIST_H
