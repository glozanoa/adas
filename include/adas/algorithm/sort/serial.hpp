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
using namespace adas::utilities;

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

      // tested - data Apr 25 2021
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
                  interchange_values(itr, inner);
              }
            if(verbose)
              print::to_stdout(first, last);
          }
      }

      // template<class RandomAccessIterator, class Compare>
      // void bubble(RandomAccessIterator first, RandomAccessIterator last, Compare comp, bool verbose)
      // /*
      //  * Comp: is a function that compare two elements and return a bool
      //  */
      // {
      //   RandomAccessIterator itr, inner;

      //   for(itr=first; itr!= last; itr++)
      //     {
      //       for(inner=itr+1; inner!=last; inner++)
      //         {
      //           if(comp(*itr, *inner))
      //             interchange_values(itr, inner);
      //         }
      //       if(verbose)
      //         print::to_stdout(first, last);
      //     }
      // }

      template<class RandomAccessIterator, class Interchange>
      void bubble(RandomAccessIterator first, RandomAccessIterator last, Interchange inter, bool verbose)
      /*
       * Comp: is a function that compare two elements and return a bool
       */
      {
        RandomAccessIterator itr, inner;

        for(itr=first; itr != last; itr++)
          {
            for(inner=itr+1; inner!=last; inner++)
              {
                if(*inner < *itr)
                  inter(itr, inner);
              }
            if(verbose)
              print::to_stdout(first, last, "\n");
          }
      }




      // tested - date Apr 30 2021
      template<class RandomAccessIterator>
      void insertion(RandomAccessIterator first, RandomAccessIterator last,
                     bool verbose)
      /*
       * Sort elements using insertion sort algorithm
       * NOTE: ONLY SORT VECTOR - CHANGE ITERATOR TYPE TO ENABLE SORT LIST DATA STRUCTURE
       */
      {
        RandomAccessIterator prev2first = prev(first);
        RandomAccessIterator itr;
        RandomAccessIterator inner;

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
              print::to_stdout(first, last);
          }
      }

      // tested - date Apr 30 2021
      template<class RandomAccessIterator, class Compare>
      void insertion(RandomAccessIterator first, RandomAccessIterator last, Compare comp,
                     bool verbose)
      /*
       * Sort elements using insertion sort algorithm
       * NOTE: ONLY SORT VECTOR - CHANGE ITERATOR TO ENABLE SORT LISTS
       */
      {
        RandomAccessIterator prev2first = prev(first);
        RandomAccessIterator itr;
        RandomAccessIterator inner;

        for(itr=first+1; itr != last; itr++)
          {
            auto key = *itr;
            inner = prev(itr);
            while(inner != prev2first && comp(key, *inner))
              {
                *next(inner) = *inner;
                inner--;
              }
            *next(inner) = key;

            if (verbose)
              print::to_stdout(first, last);
          }
      }

      template<class BidirectionalIterator>
      void bibubble(BidirectionalIterator first, BidirectionalIterator last, bool verbose)
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
                  interchange_values(aux, itr);
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
                  interchange_values(aux, itr);
                aux = itr;
              }
            init++;

            if(verbose)
              print::to_stdout(first, last);
          }
      }

      // tested - date Apr 30 2021
      template<class RandomAccessIterator>
      void selection(RandomAccessIterator first, RandomAccessIterator last, bool verbose)
      {

        RandomAccessIterator itr, min;
        for(itr=first; itr != last-1; itr++)
          {
            if(verbose)
              print::to_stdout(first, last);

            min = min_element(itr+1, last);
            if(*min  < *itr)
              interchange_values(itr, min);
          }
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
              print::to_stdout(heap.get_keys());
          }

        //return sorted;
        return heap.get_keys();
      }


      vector<int> shell_gap_sequences(unsigned int n)
      {
        vector<int> gaps;
        int gap = n/2;
        while (0 < gap)
          {
            gaps.push_back(gap);
            gap/=2;
          }

        return gaps;
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

      // template<class T>
      // vector<T> mergesort(vector<T> elements, bool verbose)
      // {
      //   typename vector<T>::iterator first = elements.begin();
      //   typename vector<T>::iterator last = elements.end();

      //   unsigned int d = distance(first, last);

      //   if(d <= 2)
      //     {
      //       if(d == 2) // sort the 2 elements, when d = 1, there is only 1 element (so it's sorted)
      //         {
      //           if(*first > *last)
      //             interchange_values(first, last);
      //         }
      //     }
      //   else
      //     {
      //       typename vector<T>::iterator midpoint = first + d/2;
      //       if(verbose)
      //         {
      //           print::to_stdout("unsorted:", first, last);
      //           print::to_stdout("lpart:", first, midpoint);
      //           print::to_stdout("rpart:", midpoint+1, last);
      //         }

      //       mergesort(first, midpoint, first_aux, midpoint_aux, verbose);
      //       mergesort(midpoint+1, last, midpoint_aux+1, last, verbose);

      //       merge(first_aux, midpoint_aux,
      //             midpoint_aux+1, last_aux,
      //             first);

      //       if(verbose)
      //         print::to_stdout("merged:", first_aux, last_aux);
      //     }

      //}
      // template<class RandomAccessIterator>
      // void mergesort(RandomAccessIterator first, RandomAccessIterator last,
      //                RandomAccessIterator first_aux, RandomAccessIterator last_aux,
      //                bool verbose)
      // {
      //   unsigned int d = distance(first, last);

      //   if(d <= 2)
      //     {
      //       if(d == 2) // sort the 2 elements, when d = 1, there is only 1 element (so it's sorted)
      //         {
      //           if(*first > *last)
      //             interchange_values(first, last);
      //         }
      //     }
      //   else
      //     {
      //       RandomAccessIterator midpoint = first + d/2;
      //       RandomAccessIterator midpoint_aux = first + d/2;
      //       if(verbose)
      //         {
      //           print::to_stdout("unsorted:", first, last);
      //           print::to_stdout("lpart:", first, midpoint);
      //           print::to_stdout("rpart:", midpoint+1, last);
      //         }

      //       mergesort(first, midpoint, first_aux, midpoint_aux, verbose);
      //       mergesort(midpoint+1, last, midpoint_aux+1, last, verbose);

      //       merge(first_aux, midpoint_aux,
      //             midpoint_aux+1, last_aux,
      //             first);

      //       if(verbose)
      //         print::to_stdout("merged:", first_aux, last_aux);
      //     }
      // }


      //template<class T>
      // improvised shellsort algorithm (implement a more efficient algorithm using iterators)
      // vector<int> shellsort(vector<int> elements, vector<int> gaps, bool verbose)
      // {
      //   for(int gap : gaps)
      //     {
      //       for(int i=gap; i<elements.size(); i++)
      //         {
      //           int tmp = elements[i];
      //           for(int j=i; j >= gap && a[j-gap] > tmp; j -= gap)
      //             {
      //               a[j] = a[j-gap];
      //             }
      //           a[j] = tmp;
      //         }
      //     }

      //   return elements;
      // }

      /*
       * WITHOUT COMPARISON SORT ALGORITHMS
       */

      //debuged - date Mar 3 2021
      template<class BidirectionalIterator>
      vector<int> counting(BidirectionalIterator init, BidirectionalIterator last, bool verbose)
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
          print::to_stdout("(init) counter:", counter);

        for(it=counter.begin(); it != counter.end(); it++)
          *it += *prev(it);

        if(verbose)
          print::to_stdout("(accumulated) counter:", counter);

        for(it=prev(last); it != prev(init); it--)
          {
            sorted[counter[*it]-1] = *it;
            counter[*it] -= 1;
            if(verbose)
              {
                print::to_stdout("sorted:", sorted);
                print::to_stdout("counter:", counter);
              }
          }

        return sorted;
      }
    }
  }
}

#endif // _SERIAL_SORT_H
