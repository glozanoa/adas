/*
 * serial search algortihms
 *
 * State:
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _SERIAL_SEARCH_H
#define _SERIAL_SEARCH_H

#include <iostream>
#include <iterator>
#include <iterator>
#include <utility>
using namespace std;

#include "../../ds/heap.hpp"
namespace ads = adas::ds;

#include "../utilities/helper.hpp"
#include "../utilities/timer.hpp"
#include "../utilities/print.hpp" // ONLY FOR TESTING PURPOSES
namespace au =  adas::utilities;

namespace adas::algorithm
{
  namespace search
  {
    namespace serial
    {
      //tested - date May 1 2021
      template<class ForwardIterator>
      ForwardIterator min_element(ForwardIterator first, ForwardIterator last)
      {
        ForwardIterator min = first;
        ForwardIterator itr = first;
        while(++itr != last)
          {
            if(*itr < *min)
              min = itr;
          }
        return min;
      }

      //tested - date May 1 2021
      template<class ForwardIterator>
      ForwardIterator _double_iterator_min_element(typename vector<ForwardIterator>::iterator first,
                                                   typename vector<ForwardIterator>::iterator last)
      {
        typename vector<ForwardIterator>::iterator min = first;
        typename vector<ForwardIterator>::iterator itr = first;
        while(++itr != last)
          {
            if(**itr < **min)
              min = itr;
          }
        return *min;
      }


      //debuged - date May 4 2021
      template<class ForwardIterator>
      ForwardIterator max_element(ForwardIterator first, ForwardIterator last)
      {
        ForwardIterator max = first;
        ForwardIterator itr = first;
        while(++itr != last)
          {
            if(*max < *itr)
              max = itr;
          }
        return max;
      }

      //tested - date May 7 2021
      template<class ForwardIterator>
      ForwardIterator _double_iterator_max_element(typename vector<ForwardIterator>::iterator first,
                                                   typename vector<ForwardIterator>::iterator last)
      {
        typename vector<ForwardIterator>::iterator max = first;
        typename vector<ForwardIterator>::iterator itr = first;
        while(++itr != last)
          {
            if(**max < **itr)
              max = itr;
          }
        return *max;
      }

      //debuged - date May 4 2021
      template<class RandomAccessIterator>
      pair<RandomAccessIterator, RandomAccessIterator> minmax_element(RandomAccessIterator first,
                                                                      RandomAccessIterator last)
      {
        RandomAccessIterator min = first;
        RandomAccessIterator max = first;
        RandomAccessIterator itr = first+1;

        while(itr != last && itr != last+1)
          {
            pair<RandomAccessIterator, RandomAccessIterator> mm = minmax(itr, itr+1);

            if(*mm.first < *min)
              min = mm.first;
            if(*max < *mm.second)
              max = mm.second;

            itr += 2;
          }
        return make_pair(min, max);
      }


      template<class ForwardIterator, class T>
      ForwardIterator secuential(ForwardIterator first, ForwardIterator last, const T value)
      {
        while(first != last)
          {
            if(*first == value)
              return first;
            first++;
          }
        return last;
      }

      template<class Container, class T>
      typename Container::iterator secuential(typename Container::iterator first,
                                              typename Container::iterator last, const T value)
      {
        return Container::secuential_search(first, last, value);
      }

      template<class ForwardIterator, class Comparison, class T>
      ForwardIterator search_prev(ForwardIterator first, ForwardIterator last,
                                  Comparison comp, const T value)
      {
        ForwardIterator prev;

        // compare the first element
        if(first != last && comp(*first, value))
          return last; // firsr element hasn't a previous element

        while(first != last)
          {
            prev = first;
            first++;
            if(comp(*first, value))
              return prev;
          }
        return last;
      }



      template<class ForwardIterator, class T>
      bool is_element(ForwardIterator first, ForwardIterator last, const T value)
      {
        while(first != last)
          {
            if(*first == value)
              return true;
            first++;
          }
        return false;
      }
    }
  }
}
#endif // _SERIAL_SEARCH_H
