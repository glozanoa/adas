/*
 * partition to implement quickstart sort algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#ifndef _PARTITION_H
#define _PARTITION_H

#include <vector>
#include <iterator>
using namespace std;

#include "./utilities/print.hpp"

namespace adas::ds
{
  template<class T>
  class Partition
  {
  private:
    vector<vector<T>>* parts;
    vector<T> pivots;
    unsigned int nelems;
  public:
    Partition(vector<T> pivots, vector<T> elements)
    {
      //constructor
      this->pivots = pivots;
      nelems = elements.size();

      parts = Partition<T>::generate(pivots, elements);
    }

    unsigned int get_nelems(){return nelems;}
    unsigned int size(){return parts->size();}
    vector<T> get_pivots(){return pivots;}
    vector<vector<T>>* get_parts(){return parts;}

    vector<T> join()
    {
      vector<T> sorted = vector<T>(nelems);
      typename vector<T>::iterator itr = sorted.begin();
      unsigned int partition_size = this->size();
      vector<T> part;

      unsigned int k=0;
      while(k < partition_size-1 )
        {
          part = parts->at(k);
          itr = copy(part.begin(), part.end(), itr);
          *itr = pivots[k];
          itr++;
          k++;
        }
      // copy of last part of partition (k = partition_size -1)
      part = this->get_part(k);
      itr = copy(part.begin(), part.end(), itr);

      return sorted;
    }

    void show()
    {
      print::to_stdout("Pivots:", pivots);
      cout << "(Parts)" << endl;
      for(int i=0; i < parts->size(); i++)
        {
          print::to_stdout("Part " + to_string(i) + ": ", parts->at(i));
        }
    }

    vector<T> get_part(unsigned int k)
    /*
     * return the part k of the partition
     */
    {
      try
        {
          unsigned int length = parts->size();
          if (length <= k)
            {
              string warning = "Index out of range";
              throw out_of_range(warning.c_str());
            }

          return parts->at(k);
        }
      catch(exception& error)
        {
          cout << error.what() << endl;
          exit(EXIT_FAILURE);
        }
    }

    void set_part(unsigned int k, vector<T> new_part)
    /*
     * set the part k of the partition with new elements
     */
    {
      try
        {
          unsigned int length = parts->size();
          if (length <= k)
            {
              string warning = "Index out of range";
              throw out_of_range(warning.c_str());
            }

          parts->at(k) = new_part;
        }
      catch(exception& error)
        {
          cout << error.what() << endl;
          exit(EXIT_FAILURE);
        }
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
          else if (pivots[npivots-1] < element)
            parts->at(npivots).push_back(element);
          else
            {
              for(int k=0; k<npivots-1; k++)
                {
                  if(pivots[k] < element && element < pivots[k+1])
                    parts->at(k+1).push_back(element);
                }
            }
        }
      return parts;
    }
  };
}

#endif // _PARTITION_H
