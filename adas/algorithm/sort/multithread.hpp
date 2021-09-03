/*
 * multi-thread sort algorithms
 *
 * Status: DEBUGED - date: May 11 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _MULTITHREAD_SORT_H
#define _MULTITHREAD_SORT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

#include "../utilities/helper.hpp"
#include "../utilities/cast.hpp"
#include "../utilities/timer.hpp"
#include "../utilities/print.hpp"
using namespace adas::utilities;

#include "../../ds/partition.hpp"
#include "../../ds/heap.hpp"

//#include "search.hpp"
#include "serial.hpp"
namespace serial = adas::algorithm::sort::serial;

#include "omp.h"


namespace adas::algorithm
{
  namespace sort
  {
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
  }
}

#endif // _MULTITHREAD_SORT_H
