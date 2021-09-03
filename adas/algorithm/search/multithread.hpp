/*
 * multithread search algortihms
 *
 * State:
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _MULTITHREAD_SEARCH_H
#define _MULTITHREAD_SEARCH_H

#include <iostream>
#include <iterator>
#include <utility>
using namespace std;

#include "../utilities/io.hpp"
#include "../utilities/helper.hpp"
#include "../utilities/timer.hpp"
#include "../utilities/print.hpp" // ONLY FOR TESTING PURPOSES
using namespace adas::utilities;

#include "serial.hpp"
namespace serial = adas::algorithm::search::serial;

#include "omp.h"

namespace adas::algorithm
{
  namespace search
  {
    namespace parallel
    {
      template<class ForwardIterator>
      ForwardIterator min_element(ForwardIterator first, ForwardIterator last, unsigned int omp_nthreads, bool verbose)
      {
        unsigned int d = distance(first, last);
        unsigned int nthreads = omp_nthreads;
        omp_set_num_threads(nthreads);
        vector<Boundaries<ForwardIterator>> limits(nthreads);
        vector<ForwardIterator> local_min(nthreads);

#pragma omp parallel shared(limits) firstprivate(first, last, nthreads)
        {
          unsigned int idthread = omp_get_thread_num();
          ForwardIterator init = first + idthread*(d/nthreads);
          ForwardIterator end = first + (idthread+1)*(d/nthreads);

          if(idthread == nthreads-1)
            end = last;

          Boundaries<ForwardIterator> limit;
          limit.init = init;
          limit.end = end;

          limits[idthread] = limit;

          ForwardIterator local_min_element =  serial::min_element(init, end);
          local_min[idthread] = local_min_element;

          // ONLY FOR DEBUG PURPOSE
          if(verbose)
            {
#pragma omp critical
              {
                cout << "(Thread " << idthread << " ) local min: " << *local_min_element << endl;
              }
            }
        }

        return serial::_double_iterator_min_element<ForwardIterator>(local_min.begin(), local_min.end());
      }

      template<class ForwardIterator>
      ForwardIterator max_element(ForwardIterator first, ForwardIterator last,
                                  unsigned int omp_nthreads, bool verbose)
      {
        unsigned int d = distance(first, last);
        unsigned int nthreads = omp_nthreads;
        omp_set_num_threads(nthreads);
        vector<Boundaries<ForwardIterator>> limits(nthreads);
        vector<ForwardIterator> local_max(nthreads);

#pragma omp parallel shared(limits) firstprivate(first, last, nthreads)
        {
          unsigned int idthread = omp_get_thread_num();
          ForwardIterator init = first + idthread*(d/nthreads);
          ForwardIterator end = first + (idthread+1)*(d/nthreads);

          if(idthread == nthreads-1)
            end = last;

          Boundaries<ForwardIterator> limit;
          limit.init = init;
          limit.end = end;

          limits[idthread] = limit;

          ForwardIterator local_max_element =  serial::max_element(init, end);
          local_max[idthread] = local_max_element;

          // ONLY FOR DEBUG PURPOSE
          if(verbose)
            {
#pragma omp critical
              {
                cout << "(Thread " << idthread << " ) local min: " << *local_max_element << endl;
              }
            }
        }

        return serial::_double_iterator_max_element<ForwardIterator>(local_max.begin(), local_max.end());
      }
    }
  }
}

#endif // _MULTITHREAD_SEARCH_H

//   template<class RandomAccessIterator, class T>
//   RandomAccessIterator binary_search(RandomAccessIterator first, RandomAccessIterator last,
//                                      const T value)
//   {
//     print::to_stdout(first, last);
//     unsigned int d = distance(first, last);
//     RandomAccessIterator midpoint  = first + d/2;

//     if(*midpoint == value)
//       return midpoint;
//     else if(1 < d)
//       {
// #pragma omp parallel sections
//         {
// #pragma omp section
//           {
//             RandomAccessIterator lsearch = binary_search(first, midpoint, value);
//             if(*lsearch == value) return lsearch;
//           }

// #pragma omp section
//           {
//             RandomAccessIterator rsearch = binary_search(midpoint+1, last, value);
//             if(*rsearch == value) return rsearch;
//           }
//         }
//       }
//     return last;
//   }
