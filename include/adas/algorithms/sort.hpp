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

#include "search.hpp"
#include "helper.hpp"
#include "cast.hpp"
#include "timer.hpp"
#include "print.hpp"
#include "heap.hpp"
#include "partition.hpp"
#include "omp.h"

// typedef enum ORDER
//   {


//   }ORDER;


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
    {
      RandomAccessIterator itr, inner;

      for(itr=first; itr!= last-1; itr++)
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

  namespace parallel
  /*
   * parallel (multi thread) sort algorithms
   */
  {

    template <class RandomAccessIterator>
    void multi_merge(vector<Boundaries<RandomAccessIterator>> limits, bool verbose)
    /*
     * Merge several sorted parts of a array into it.
     * (using an auxiliary vector to stored intermediate merges)
     */
    {
      unsigned int size = limits.size();
      unsigned int nelems = 0;
      for(Boundaries<RandomAccessIterator> limit : limits)
        nelems += distance(limit.init, limit.end);

      // auxiliary vector to store intermediate merges
      vector<typename RandomAccessIterator::value_type> merge_aux;
      merge_aux = vector<typename RandomAccessIterator::value_type>(nelems);
      RandomAccessIterator merge_itr = merge_aux.begin();
      RandomAccessIterator init_merge = merge_aux.begin();

      Boundaries<RandomAccessIterator> limit = limits[0];
      RandomAccessIterator init = limit.init;

      // merge sorted sub containers
      for(unsigned int k=1; k<size; k++)
        {
          Boundaries<RandomAccessIterator> next_limit = limits[k];
          merge_itr = serial::merge(limit.init, limit.end,
                                    next_limit.init, next_limit.end,
                                    merge_itr);
          copy(init_merge, merge_itr, init); // overwrite partitions by merged elements
          limit.end = next_limit.end;
          limit.init = init; // limit.init iterator is modify (incremented) in serial::merge
          merge_itr = init_merge;
          if(verbose)
            print::to_stdout("merge:", merge_aux); // ONLY FOR DEBUGING PURPOSES
        }
    }


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
      unsigned size = partition.size();

#pragma omp parallel for shared(partition) firstprivate(size)
      for(unsigned int k = 0; k < size; k++)
        {
          vector<T> part = partition.get_part(k);
          if(1 < part.size()) // if part has some elements, otherwise it's sorted
            {
              serial::bubble(part.begin(), part.end(), verbose);
              // ONLY FOR DEBUG PURPOSE
              #pragma omp critical
              {
                unsigned int idthread = omp_get_thread_num();
                cout << "Thread " << idthread << ": ";
                print::to_stdout(part);
              }
              partition.set_part(k, part);
            }
        }

      return partition.join();
    }


    template<class RandomAccessIterator, class SerialSortAlgorithm>
    void spm(RandomAccessIterator first, RandomAccessIterator last,
             unsigned int omp_nthreads, SerialSortAlgorithm ssa, bool verbose)
    /*
     * spm : split, process and merge
     * This algorithm sort a container in parallel using some serial sort algorithm.
     * Splitting it by the number of threads, then proces each part in parallel with a serial algorithm
     * and finaly merge the sorted parts.
     */
    {
      unsigned int d = distance(first, last);
      unsigned int nthreads = omp_nthreads;
      omp_set_num_threads(nthreads);
      vector<Boundaries<RandomAccessIterator>> limits(nthreads);

#pragma omp parallel shared(limits) firstprivate(first, last, verbose, nthreads)
      {
        unsigned int idthread = omp_get_thread_num();
        RandomAccessIterator init = first + idthread*(d/nthreads);
        RandomAccessIterator end = first + (idthread+1)*(d/nthreads);

        if(idthread == nthreads-1)
          end = last;

        Boundaries<RandomAccessIterator> limit;
        limit.init = init;
        limit.end = end;

        limits[idthread] = limit;

        ssa(init, end, false);
        //ONLY FOR DEBUGING PURPOSES
        if(verbose)
          {
#pragma omp critical
            {
              print::to_stdout("Thread " + to_string(idthread) + ":", init, end);
            }
          }
      }

      multi_merge(limits, verbose);
    }

    template<class RandomAccessIterator>
    void bubble(RandomAccessIterator first, RandomAccessIterator last,
                unsigned int omp_nthreads, bool verbose)
    {
      spm(first, last, omp_nthreads, serial::bubble<RandomAccessIterator>, verbose);
    }


    template<class RandomAccessIterator>
    void bibubble(RandomAccessIterator first, RandomAccessIterator last,
                   unsigned int omp_nthreads, bool verbose)
    {
      spm(first, last, omp_nthreads, serial::bibubble<RandomAccessIterator>, verbose);
    }


    template<class RandomAccessIterator>
    void selection(RandomAccessIterator first, RandomAccessIterator last,
                   unsigned int omp_nthreads, bool verbose)
    {
      spm(first, last, omp_nthreads, serial::insertion<RandomAccessIterator>, verbose);
    }


    template<class RandomAccessIterator>
    void insertion(RandomAccessIterator first, RandomAccessIterator last,
                   unsigned int omp_nthreads, bool verbose)
    {
      spm(first, last, omp_nthreads, serial::selection<RandomAccessIterator>, verbose);
    }
  }
};
#endif // _SORT_H