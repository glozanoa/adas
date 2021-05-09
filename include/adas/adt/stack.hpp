/*
 * Template stack class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _STACK_H
#define _STACK_H

#include <algorithm>
#include <vector>
using namespace std;

template<class T>
class Stack
{
protected:
  vector<T> keys;
  unsigned int size;

public:
  Stack():size{0} {}
  Stack(T keys[], unsigned size)
    :size{size}
  {
    this->keys = vector<T>(size);
    copy(keys, keys+size, this->keys.begin());
  }

  Stack(vector<T> keys)
    :keys{keys}
  {
    size = keys.size();
  }

  void push(T key)
  {
    keys.push_back(key);
  }

  void pop()
  {
    keys.pop_back();
  }
}

#endif //_STACK_H
