/*
 * Queue template class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
#include <vector>
using namespace std;

#include "heap.hpp"
#include "exceptions/general.hpp"

typedef enum QT // queue type
  {
    MAX_PRIORITY,
    MIN_PRIORITY
  }QT;

template <class T>
class Queue: Heap<T>
{
private:
  vector<T> handle;
  QT type;

public:
  Queue(vector<T> keys, QT type):Heap<T>(keys)
  {
    this->type = type;
    if(type == QT::MAX_PRIORITY)
      this->build_max_heap(false);
    else
      this->build_min_heap(false);
  }

  T maximum()
  {
    if(type == QT::MAX_PRIORITY)
      return this->get_root();
    else
      {
        // IMPLEMENT ME
        return 0;
      }
  }

  T extract_max()
  /*
   * O(lg n) : MAX PRIORITY QUEUE
   */
  {
    try
      {
        if(this->size < 1)
          throw Exception("Heap underflow");

        if(type == QT::MAX_PRIORITY)
          {
            T max = this->maximum();
            this->keys[0] = this->keys[this->size-1];
            this->resize(this->size-1);
            this->max_heapify(0);
          }
        else
          {
            //IMPLEMENT ME
            T max = 0;
          }
        return max;
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
      }
  }

  void increase_key(unsigned int i, T key)
  /*
   * O(lg n): MAX PRIORITY QUEUE
   */
  {
    try
      {
        if(type == QT::MAX_PRIORITY)
          {
            if(key < this->get_key(i))
              throw Exception("New key is smaller than current key");

            this->set_key(i, key);

            unsigned int parent_index = i/2;

            while(i > 0 &&
                  this->get_key(parent_index) > this->get_key(i))
              {
                this->interchange(i, parent_index);
                i = parent_index;
              }
          }
        else
          {
            //IMPLEMENT ME
          }
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
      }
  }

  void insert(T key)
  /*
   * O(lg n): MAX PRIORITY QUEUE
   */
  {
    if(type == QT::MAX_PRIORITY)
      {
        unsigned int nkeys = this->get_nkeys();
        if(size < nkeys)
          this->set_key(size, key);
        else // size == nkeys, so we need to expand the vector keys
          {
            this->keys.push_back(0);
            this->increase_key(size, key);
          }
        this->resize(size+1);
      }
    else
      {
        //IMPLEMENT ME
      }
  }
};

#endif //_QUEUE_H
