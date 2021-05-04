 /*
 * Testing bubble sorting algorithm
 *
 * Updated - date : Mar 4 2021
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "../../include/sort.hpp"
#include "../../include/print.hpp"
#include "../../include/timer.hpp"
#include "../../include/io.hpp"

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

int main()
{

  Timer time;
  bool verbose = true;

  vector<int> numbers = read::from_file<int>("tests/data/bs.txt");

  //array and vector to test search::bubble algorithm
  unsigned int n = numbers.size();
  int arr[n];
  vector<int> cnumbers = vector<int>(n);
  copy(numbers.begin(), numbers.end(), arr);
  copy(numbers.begin(), numbers.end(), cnumbers.begin());


  cout << "sorting numbers in vector<T> data structure" << endl;
  time.start();
  sort::bubble(numbers.begin(), numbers.end(), verbose);
  time.stop();
  time.report("Elapsed time (normal comparison)");

  //printing sorted numbers
  print::to_stdout("Sorted vector:", numbers);


  cout << "sorting numbers in vector<T> data structure (custom comparison)" << endl;
  time.start();
  sort::bubble(cnumbers.begin(), cnumbers.end(), smaller, verbose);
  time.stop();
  time.report("Elapsed time (custom comparison)");

  //printing sorted numbers
  print::to_stdout("Sorted vector:", cnumbers);


  cout << "sorting numbers in array data structure" << endl;
  time.start();
  sort::bubble(arr, arr+n, false);
  time.stop();
  time.report("Elapsed time (sorting array)");

  //saving sorted numbers
  write::to_file(arr, arr+n, "tests/data/sorted_bubble.txt");

  return 0;
}
