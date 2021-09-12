/*
 * Single Linked Circular List template data structure
 *
 * Status:
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _SLCLIST_H
#define _SLCLIST_H

#include <iostream>
#include <iterator>
#include <vector>
#include <initializer_list>


#include "../exceptions/general.hpp"

#include "../utilities/print.hpp"
namespace au = adas::utilities;

#include "single_linked_list.hpp"
#include "single_linked_node.hpp"
using namespace adas::ds;

namespace adas::ds
{

  template<class T>
  class SLCList : public SLList<T>
  /*
   * SLCList : Single Linked Circular List
   */
  {
  public:
    SLCList();
    SLCList(std::initializer_list<T> keys);


    // Methods to manipulate DLCList<T>
    SLNode<T>* get_head(){return this->head;}
    void push_back(SLNode<T>* node);
    void push_back(T key);

    template<class L>
    friend ostream& operator<<(ostream& out, SLCList<L> list);
  };

  template<class T>
  SLCList<T>::SLCList()
  {
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
    this->next2tail =nullptr; // node to generate "end" iterator
  }

  template<class T>
  SLCList<T>::SLCList(std::initializer_list<T> keys)
    :SLCList<T>()
  {
    for(T key : keys)
      this->push_back(key);
  }

  template<class T>
  void SLCList<T>::push_back(SLNode<T>* node)
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
  void SLCList<T>::push_back(T key)
  {
    SLNode<T>* node = new SLNode<T>(key);
    this->push_back(node);
  }

  template<class T>
  ostream& operator<<(ostream& out, SLCList<T> list)
  {
    unsigned int counter = 0; //count how many time the head node is printed

    SLNode<T>* head = list.get_head();
    typename SLList<T>::iterator itr = list.begin();
    while (counter < 2) // if counter == 2, then we have printed all element of cricular list
      {
        SLNode<T>* node = itr->get_node();
        out << node << endl;
        if(node == head)
          counter++;

        itr++;
      }

    return out;
  }


} // end namespace adas::ds


#endif //_SLCLIST_H
