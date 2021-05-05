/*
 * sort algorithms
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _SORT_H
#define _SORT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#include "helper.hpp"
#include "cast.hpp"
#include "timer.hpp"
#include "print.hpp"
#include "heap.hpp"
//#include "partition.hpp"


namespace sort
{

  /*
   * WITH COMPARISON SORT ALGORITHMS
   */

  // tested - data Apr 25 2021
  template<class RandomAccessIterator>
  void bubble(RandomAccessIterator first, RandomAccessIterator last, bool verbose)
  {
    RandomAccessIterator itr, inner;

    for(itr=first; itr!= last-1; itr++)
      {
        for(inner=itr+1; inner!=last; inner++)
          {
            if(*itr > *inner)
              interchange_values(itr, inner);
          }
        if(verbose)
          print::to_stdout(first, last);
      }
  }

  template<class RandomAccessIterator, class Compare>
  void bubble(RandomAccessIterator first, RandomAccessIterator last, Compare comp, bool verbose)
  /*
   * Comp: is a function that compare two elements and return a bool
   */
  {
    RandomAccessIterator itr, inner;

    for(itr=first; itr!= last-1; itr++)
      {
        for(inner=itr+1; inner!=last; inner++)
          {
            if(comp(*itr, *inner))
              interchange_values(itr, inner);
          }
        if(verbose)
          print::to_stdout(first, last);
      }
  }




  // tested - date Apr 30 2021
  template<class RandomAccessIterator>
  void insertion(RandomAccessIterator first, RandomAccessIterator last,
                 bool verbose, bool timer)
  /*
   * Sort elements using insertion sort algorithm
   * NOTE: ONLY SORT VECTOR - CHANGE ITERATOR TYPE TO ENABLE SORT LIST DATA STRUCTURE
   */
  {
    Timer time;
    if(timer)
      time.start();

    RandomAccessIterator prev2first = prev(first);
    RandomAccessIterator itr;
    RandomAccessIterator inner;

    for(itr=first+1; itr != last; itr++)
      {
        auto key = *itr;
        inner = prev(itr);
        while(inner != prev2first && *inner > key)
          {
            *next(inner) = *inner;
            inner--;
          }
        *next(inner) = key;

        if (verbose)
          print::to_stdout(first, last);
      }

    if(timer)
      {
        time.stop();
        time.default_report();
      }
  }

  // tested - date Apr 30 2021
  template<class RandomAccessIterator, class Compare>
  void insertion(RandomAccessIterator first, RandomAccessIterator last, Compare comp,
                 bool verbose, bool timer)
  /*
   * Sort elements using insertion sort algorithm
   * NOTE: ONLY SORT VECTOR - CHANGE ITERATOR TO ENABLE SORT LISTS
   */
  {
    Timer time;
    if(timer)
      time.start();

    RandomAccessIterator prev2first = prev(first);
    RandomAccessIterator itr;
    RandomAccessIterator inner;

    for(itr=first+1; itr != last; itr++)
      {
        auto key = *itr;
        inner = prev(itr);
        while(inner != prev2first && comp(*inner, key))
          {
            *next(inner) = *inner;
            inner--;
          }
        *next(inner) = key;

        if (verbose)
          print::to_stdout(first, last);
      }

    if(timer)
      {
        time.stop();
        time.default_report();
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
            if(*itr > *aux) // aux = min
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

        min = minimum(itr+1, last);
        if(*itr > *min)
          interchange_values(itr, min);
      }
  }

  // TRY TO IMPLEMENT WITH ITERATOR IF IT IS POSSIBLE
  template <class T>
  vector<T> heap_sort(vector<T> keys)
  {
    //vector<T> sorted;
    Heap<T> heap = Heap<T>(keys);
    heap.build_max_heap(false);

    for(int heap_size=heap.get_size(); heap_size>1; heap_size--)
      {
        heap.interchange(0, heap_size-1);
        heap.resize(heap_size-1);
        heap.max_heapify(0, false);
        heap_size = heap.get_size();
      }

    //return sorted;
    return heap.get_keys();
  }


  vector<int> shell_gap_sequences(unsigned int n)
  {
    vector<int> gaps;
    int gap = n/2;
    while (gap > 0)
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


  template<class T>
  vector<T> quicksort(vector<T> elements, vector<T> pivots, bool verbose)
  /*
   * Improve efficiency of quicksort algorithm:
   * + Reimplement Partition<T> class using pointer (to avoid copy data)
   * + Parallelize for loop in quicksort body
   * + change of sortng algorithm to sort partition's parts (codify mergesort algorithm)
   */
  {
    Partition<T> partition = Partition<T>(pivots, elements);

    unsigned int k = 0;
    for(vector<T> part : *partition.get_parts())
      {
        if(part.size() > 1) // if part has some elements, otherwise it's sorted
          {
            bubble(part.begin(), part.end(), verbose);
            partition.set_part(k, part);
            k++;
          }
      }

    return partition.join();
  }

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
};
#endif // _SORT_H
