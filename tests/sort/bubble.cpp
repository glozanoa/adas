 /*
 * Testing bubble sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "../../include/sort.hpp"
#include "../../include/helper.hpp"
#include "../../include/print.hpp"
#include "../../include/timer.hpp"
#include "../../include/io.hpp"

/*  NOTE: Compile with Makefile and run in ROOT DIRECTORY OF REPOSITORY */

/*
 * Custom function to compare elements
 */
template <typename T>
bool smaller(T x, T y)
/*
 * if x is smaller than y then return true, otherwise return false
 */
{
  return x < y;
}

void swap(int*x, int* y)
{
  int aux = *x;
  *x = *y;
  *y = aux;
}

void bubbleSort(int arr[], int n)
{
  int i, j;
  bool swapped;
  for (i = 0; i < n-1; i++)
    {
      swapped = false;
      for (j = 0; j < n-i-1; j++)
        {
          if (arr[j] > arr[j+1])
            {
              swap(&arr[j], &arr[j+1]);
              swapped = true;
            }
        }

      // IF no two elements were swapped by inner loop, then break
      if (swapped == false)
        break;
    }
}

int main()
{

  Timer time;

  // ENABLE THIS LINE IF YOU WANT TO READ YOUR DATA FROM A FILE
  vector<int> numbers = read::from_file<int>("tests/data/bs.txt");
  unsigned int n = numbers.size();
  int arr[n];
  int arr2[n];
  copy(numbers.begin(), numbers.end(), arr);
  copy(numbers.begin(), numbers.end(), arr2);

  // USING NORMAL ARRAYS
  // unsigned int n = 4;
  // int numbers[n] = {2, 7, 1, 9};
  // int copy_numbers[n] = {2, 7, 1, 9};

  //cout << "normal sort (using default order [crescent])" << endl;
  cout << "algorithm with iterators" << endl;
  time.start();
  // IF YOU WANT TO USE vector class, replace numbers by numbers.begin() and numbers + SIZE by numbers.end()
  //sort::bubble(numbers, numbers+n, true);
  sort::bubble(arr2, arr2+n, false);
  time.stop();
  time.report("Elapsed time (sort with iterators)");

  cout << "algorithm without iterators" << endl;
  time.start();
  // IF YOU WANT TO USE vector class, replace numbers by numbers.begin() and numbers + SIZE by numbers.end()
  //sort::bubble(numbers, numbers+n, true);
  bubbleSort(arr,n);
  time.stop();
  time.report("Elapsed time (sort without iterators)");

  write::to_file(arr2, arr2+n, "tests/data/sorted.txt");

  // cout << "custom sort (using a custom function [decreasing])" << endl;
  // time.start();
  // IF YOU WANT TO USE vector class, check the above comment
  // sort::bubble(copy_numbers, copy_numbers+n, smaller<int>, true);
  // time.stop();
  // time.report("Elapsed time (custom sort)");

  return 0;
}
