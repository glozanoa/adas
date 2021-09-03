/*
 * serial (single-thread) sort algorithms
 *
 * Status: DEBUGED - date: May 11 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _SERIAL_SORT_H
#define _SERIAL_SORT_H

#include "../utilities/helper.hpp"
#include "../utilities/cast.hpp"
#include "../utilities/timer.hpp"
#include "../utilities/print.hpp"
namespace au = adas::utilities;

#include "../../ds/heap.hpp"
namespace ads = adas::ds;


namespace adas::algorithm
{
  namespace sort
  {
    namespace serial
    /*
     * Serial (single thread) sort algorithms
     */
    {
      /*
       * WITH COMPARISON SORT ALGORITHMS
       */

      template<class RandomAccessIterator>
      void bubble(RandomAccessIterator first, RandomAccessIterator last, bool verbose)
      /*
       * Supported containers: vector<T>, array[T]
       */
      {
        RandomAccessIterator itr, inner;

        for(itr=first; itr!= last; itr++)
          {
            for(inner=itr+1; inner!=last; inner++)
              {
                if(*inner < *itr)
                  au::interchange_values(itr, inner);
              }
            if(verbose)
              au::print::to_stdout(first, last);
          }
      }


      template<class Container>
      void bubble(typename Container::iterator first, typename Container::iterator last, bool verbose)
      /*
       * bubble sort algorithm for adas's containers
       * Supported containers: DLList<T>
       */
      {
        Container::bubble(first, last, verbose);
      }


      template<class BidirectionalIterator>
      void bibubble(BidirectionalIterator first, BidirectionalIterator last, bool verbose)
      /*
       * Supported containers: vector<T>, array[T]
       */
      {

        BidirectionalIterator init = prev(first);
        BidirectionalIterator end = last;

        BidirectionalIterator itr; // iterator to iterate in bidirectional data structure
        BidirectionalIterator aux; // auxiliary iterator to store maximum and minimum element


        while(init != end)
          {
            itr=init;
            aux = init;
            while(++itr != end)
              {
                if(*itr < *aux) // aux = max
                  au::interchange_values(aux, itr);
                aux = itr;
              }

            //end--;
            if(--end == init)
              break;

            itr = end;
            aux = end;

            while(--itr != init)
              {
                if(*aux < *itr) // aux = min
                  au::interchange_values(aux, itr);
                aux = itr;
              }
            init++;

            if(verbose)
              au::print::to_stdout(first, last, "\n");
          }
      }

      template<class Container>
      void bibubble(typename Container::iterator first, typename Container::iterator last, bool verbose)
      /*
       * bibubble sort algorithm for adas's containers
       * Supported containers: DLList<T>
       */
      {
        Container::bibubble(first, last, verbose);
      }


      template<class RandomAccessIterator>
      void selection(RandomAccessIterator first, RandomAccessIterator last, bool verbose)
      /*
       * Supported containers: vector<T>, array[T]
       */
      {

        RandomAccessIterator itr, min;
        for(itr=first; itr != last-1; itr++)
          {
            if(verbose)
              au::print::to_stdout(first, last);

            min = min_element(itr+1, last);
            if(*min  < *itr)
              au::interchange_values(itr, min);
          }
      }


      template<class Container>
      void selection(typename Container::iterator first, typename Container::iterator last, bool verbose)
      /*
       * selection sort algorithm for adas's containers
       * Supported containers: DLList<T>
       */
      {
        Container::selection(first, last, verbose);
      }


      // tested - date Apr 30 2021
      template<class BidirectionalIterator>
      void insertion(BidirectionalIterator first, BidirectionalIterator last, bool verbose)
      /*
       * Supported containers: vector<T>, array[T]
       */
      {
        BidirectionalIterator prev2first = prev(first);
        BidirectionalIterator itr;
        BidirectionalIterator inner;

        for(itr=first+1; itr != last; itr++)
          {
            auto key = *itr;
            inner = prev(itr);
            while(inner != prev2first && key < *inner)
              {
                *next(inner) = *inner;
                inner--;
              }
            *next(inner) = key;

            if (verbose)
              au::print::to_stdout(first, last);
          }
      }


      //tested - date May 20 2021
      template<class Container>
      void insertion(typename Container::iterator first, typename Container::iterator last, bool verbose)
      /*
       * selection sort algorithm for adas's containers
       * Supported containers: DLList<T>
       */
      {
        Container::insertion(first, last, verbose);
      }

      // TRY TO IMPLEMENT WITH ITERATOR IF IT IS POSSIBLE
      template <class T>
      vector<T> heap_sort(vector<T> keys, bool verbose)
      {
        //vector<T> sorted;
        ads::Heap<T> heap = ads::Heap<T>(keys);
        heap.build_max_heap(false);

        int  heap_size = heap.get_size();
        while(1 < heap_size)
          {
            heap.interchange(0, heap_size-1);
            heap.resize(heap_size-1);
            heap.max_heapify(0, false);
            heap_size = heap.get_size();
            if(verbose)
              au::print::to_stdout(heap.get_keys());
          }

        //return sorted;
        return heap.get_keys();
      }

      template <class InputIterator1, class InputIterator2, class OutputIterator>
      OutputIterator merge(InputIterator1 first1, InputIterator1 last1,
                           InputIterator2 first2, InputIterator2 last2,
                           OutputIterator result)
      /*
       * Combines the elements in the sorted ranges [first1,last1) and [first2,last2),
       * into a new range beginning at result.
       */
      {
        while(true)
          {
            if(first1 == last1) return copy(first2, last2, result);
            if(first2 == last2) return copy(first1, last1, result);

            *result++ = (*first2 < *first1)? *first2++ : *first1++;
          }
      }

      /*
       * WITHOUT COMPARISON SORT ALGORITHMS
       */

      //debuged - date Mar 3 2021
      template<class BidirectionalIterator>
      vector<int> counting(BidirectionalIterator init, BidirectionalIterator last, bool verbose)
      /*
       * Supported containers: vector<int>, array[int]
       */
      {
        unsigned int nelem = distance(init, last);
        vector<int> sorted = vector<int>(nelem);

        auto minmax = minmax_element(init, last);
        unsigned k = (*minmax.second - *minmax.first) +1;
        vector<int> counter = vector<int>(k, 0);
        vector<int>::iterator it;

        for(it=init; it != last; it++)
          counter[*it] += 1;

        if(verbose)
          au::print::to_stdout("(init) counter:", counter);

        for(it=counter.begin(); it != counter.end(); it++)
          *it += *prev(it);

        if(verbose)
          au::print::to_stdout("(accumulated) counter:", counter);

        for(it=prev(last); it != prev(init); it--)
          {
            sorted[counter[*it]-1] = *it;
            counter[*it] -= 1;
            if(verbose)
              {
                au::print::to_stdout("sorted:", sorted);
                au::print::to_stdout("counter:", counter);
              }
          }

        return sorted;
      }
    }
  }
}

#endif // _SERIAL_SORT_H
