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
  void bidirectional_bubble(BidirectionalIterator first, BidirectionalIterator last, bool verbose)
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



// REWRITE USING BINARY SEARCH IN BINARY TREES
// static vector<int> pratt_gap_sequences(unsigned int n)
// {
//   int p = 0;
//   int q = 0;
//   int ptmp, qtmp;
//   vector<int> gaps = {1}; //pow(2, p)*pow(3, q)

//   unsigned int size = gaps.size();
//   while (size <= n)
//     {
//       ptmp = three_smooth(p+1, q);
//       qtmp = three_smooth(p, q+1);
//       if(ptmp > qtmp)
//         {
//           gaps.push_back(qtmp);
//           q++;
//         }
//       else
//         {
//           gaps.push_back(ptmp);
//           p++;
//         }
//       size = gaps.size();
//     }

//   return gaps;
// }

  // static vector<T> shellsort(vector<T> elements, vector<int> gaps, bool verbose)
  // /*
  //  * Sort a vector of elements using shellsort sort algorithm
  //  * Input:
  //  *     gaps decreasing gaps vector
  //  * return:
  //  *     sorted vector
  //  */
  // {
  //   unsigned int length = elements.size();

  //   for(int gap: gaps)
  //     {
  //       for(int i=gap; i<length; i++)
  //         {
  //           T tmp = elements[i];
  //           int j;
  //           for(j=i; j>=gap && elements[j-gap] > tmp; j-=gap)
  //             elements[j] = elements[j-gap];

  //           elements[j] = tmp;
  //         }

  //       if(verbose)
  //         {
  //           cout << "(gap " << gap << ")" << endl;
  //           print(elements);
  //         }
  //     }

  //   return elements;
  // }


  // // SOLVE BUG
  // static vector<T> binary_insertion(vector<T> elements, bool verbose)
  // /*
  //  * Sort vector of elements using binary insertion sort algorithm
  //  */
  // {
  //   unsigned int length = elements.size();
  //   T auxi;
  //   int k;
  //   T init, end;
  //   T midpoint;

  //   for(int i=1; i<length; i++)
  //     {
  //       if(verbose)
  //         cout << "(Iteration " << i-1 << ")" << endl;

  //       auxi = elements[i];
  //       init = 0;
  //       end = i-1;
  //       while(init <= end)
  //         {
  //           midpoint = (int)((init+end)/2);
  //           if(auxi < elements[midpoint])
  //             end = midpoint -1;
  //           else
  //             init = midpoint +1;

  //           if (verbose)
  //             cout << "init: "<< init << ", midpoint: " << midpoint << ", end: " << end << endl;
  //         }
  //       for(k = i-1; i >= end; i--)
  //         elements[k+1] = elements[k];

  //       elements[end] = auxi;

  //       if(verbose)
  //         print(elements);
  //     }

  //   return elements;
  // }

  // static vector<T> quicksort(vector<T> elements, vector<T> pivots, bool verbose)//, SortAlgorithm f)
  // {
  //   Partition<T> partition = Partition<T>(pivots, elements);
  //   vector<vector<T>>* parts = partition.get_parts();
  //   int k = 0;
  //   for(vector<T> part: *parts)
  //     parts->at(k) = Sort<T>::bubble(part, false);

  //   return partition.join();
  // }

  // ////////////// extern sort algorithms /////////////

  // static void extern_merge(ifstream f1, ifstream f2, string out_name)
  // /*
  //  * meger sorted files
  //  */
  // {
  //   ofstream out = ofstream(out_name);

  //   try{
  //     if(!f1.is_open()){
  //       string warning = "File f1 didn't open";
  //       out.close();
  //       throw ios_base::failure(warning.c_str());
  //         }
  //     else if (!f2.is_open()){
  //       string warning = "File f2 didn't open";
  //       f1.close();
  //       out.close();
  //       throw ios_base::failure(warning.c_str());
  //         }
  //     else{
  //       string aux; // element to read buffer of files f1 and f2
  //       T r1, r2; // elements to read files f1 and f2

  //       r1 = readline<T>(f1);
  //       r2 = readline<T>(f2);

  //       while (!(f1.eof() || f2.eof()))
  //         {
  //           if(r1 <= r2)
  //             {
  //               out << r1 << endl;
  //               r1 = readline<T>(f1);
  //             }
  //           else
  //             {
  //               out << r2 << endl;
  //               r2 = readline<T>(f2);
  //             }
  //         }

  //       if(!f1.eof())
  //         {
  //           do{
  //             r1 = readline<T>(f1);
  //             out << r1 << endl;
  //           }while(!f1.eof());
  //         }
  //       if(!f2.eof())
  //         {
  //           do{
  //             r2 = readline<T>(f2);
  //             out << r2 << endl;
  //           }while(!f2.eof());
  //         }
  //     }

  //     f1.close();
  //     f2.close();
  //     out.close();
  //   }

  //   catch(exception& error){
  //     if(f1.is_open())
  //       f1.close();

  //     if(f2.is_open())
  //       f2.close();

  //     if(out.is_open())
  //       out.close();

  //     cout << error.what() << endl;
  //   }
  // }
//};

#endif // _SORT_H
