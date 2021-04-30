/*
 * partition to implement quickstart sort algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _PARTITION_H
#define _PARTITION_H

#include <vector>
using namespace std;

//#include "sort.hpp"}
#include "helper.hpp"

template<class T>
class Partition
{
private:
  vector<vector<T>>* parts;
  vector<T> pivots;
  vector<T> elements;
public:
  Partition(vector<T> pivots, vector<T> elements)
  {
    //constructor
    this->pivots = pivots;
    this->elements = elements;

    //pivots = Sort<T>::bubble(unsort_pivots, false); USER <algorithms> library
    parts = Partition<T>::generate(pivots, elements);
  }

  unsigned int size(){return parts->size();}
  vector<T> get_pivots(){return pivots;}
  vector<vector<T>>* get_parts(){return parts;}

  vector<T> join()
  {
    vector<T> sorted;

    for(int k=0; k< parts->size(); k++)
      {

      }
  }

  void show()
  {
    cout << "(Pivots)" << endl;
    print(pivots);
    cout << "(Parts)" << endl;
    for(int i=0; i < parts->size(); i++)
    {
      print(parts->at(i));
    }
    
  }

  vector<T> get_part(unsigned int k)
  /*
   * return the part k of the partition
   */
  {
    unsigned int length = parts->size();
    if (k >= length)
      {
        string warning = "Index out of range";
        throw out_of_range(warning.c_str());
      }
    else
      return parts->at(k);
  }

  void set_part(unsigned int k, vector<T> new_part)
  /*
   * set the part k of the partition with new elements
   */
  {
    unsigned int length = parts->size();
    if (k >= length)
      {
        string warning = "Index out of range";
        throw out_of_range(warning.c_str());
      }
    else
      parts->at(k) = new_part;
  }
  template<typename T1, class SortAlgorithm>
  vector<T1> sort_part(unsigned int k, bool verbose, SortAlgorithm f)
  /*
   * Sort part k with f sort algorithm
   */
  {
    vector<T1> part = this->get_part(k);
    vector<T1> sorted_part;

    sorted_part = f(part, verbose);
    this->set_part(k, sorted_part);
  }

  static vector<vector<T>>* generate(vector<T> pivots, vector<T> elements)
  /*
   * Generate a partition of the elements vector with the supplied pivots
   * NOTE: pivots will be sorted
   */
  {
    unsigned int npivots = pivots.size();
    vector<vector<T>>* parts = new vector<vector<T>>(npivots+1, vector<T>());

    for(T element: elements)
      {
        if (element < pivots[0])
          parts->at(0).push_back(element);
        else if (element > pivots[npivots-1])
          parts->at(npivots).push_back(element);
        else
          {
            for(int k=0; k<npivots-1; k++)
              {
                if(element > pivots[k] && element < pivots[k+1])
                  parts->at(k+1).push_back(element);
              }
          }
      }
    return parts;
  }
};
#endif // _PARTITION_H
