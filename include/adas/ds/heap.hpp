/*
 * Heap template class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _HEAP_H
#define _HEAP_H

#include <iostream>
using namespace std;

#include "./utilities/print.hpp"

template<class T>
class Heap
{
private:
  vector<T> keys;
  int size;

public:

  Heap(vector<T> keys)
    :keys{keys}
  {
    size = keys.size();
  }

  unsigned int get_nkeys(){return keys.size();}

  T get_key(unsigned int k)
  {
    try
      {
        if(size <= k)
          throw out_of_range("(get_key function) Index of key out of range.");
        return keys[k];
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  T get_parent_key(unsigned int k)
  {
    try
      {
        if(size <= k)
          throw out_of_range("(get_parent_key function) Index of key out of range.");
        k/=2;
        return keys[k];
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  void set_key(unsigned int k, T key)
  {
    try
      {
        if(size <= k)
          throw out_of_range("(set_key function) Index of key out of range.");
        keys[k] = key;
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  T get_root(){return keys[0];}
  vector<T> get_keys(){return keys;}
  void interchange(unsigned int k, unsigned int i)
  /*
   * Interchange element on the heap
   */
  {
    try
      {
        if(k >= size || i >= size)
          throw out_of_range("Index out of range");
        T tmp = keys[k];
        keys[k] = keys[i];
        keys[i] = tmp;
      }
    catch(exception& error)
      {
        cout << error.what() << endl;
        exit(EXIT_FAILURE);
      }
  }

  int get_size(){return size;}
  void resize(unsigned int heap_size){size = heap_size;}
  void max_heapify(int i, bool verbose)
  {
    int left = 2*i+1;
    int rigth = 2*i+2;
    int largest = i;


    if(left < size && keys[i] < keys[left])
      largest = left;
    if(rigth < size && keys[i] < keys[rigth] &&
       left < size && keys[left] < keys[rigth])
      largest = rigth;

    if(largest != i)
      {
        interchange_values(&keys[i], &keys[largest]);
        if (verbose)
          this->print_keys();
        this->max_heapify(largest, verbose);
      }
  }

  void build_max_heap(bool verbose)
  {
    for(int i = size/2; i>=0; i--)
      this->max_heapify(i, verbose);
  }

  void min_heapify(int i, bool verbose)
  {
    // IMPLEMENT ME
  }

  void build_min_heap(bool verbose)
  {
    // IMPLEMENT ME
  }

  // void build_max_heap()
  // {
  //   this->build_max_heap(false);
  // }

  void print_keys()
  {
    print::to_stdout(keys);
  }
};

#endif //_HEAP_H
