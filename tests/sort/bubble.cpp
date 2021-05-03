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
#include "../../include/read.hpp"

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

int main()
{

  Timer time;
  time.start();

  // ENABLE THIS LINE IF YOU WANT TO READ YOUR DATA FROM A FILE
  //vector<int> numbers = Read<int>::from_file("tests/data/random.txt");

  //vector<int> numbers = {2, 7, 1, 9};

  // USING NORMAL ARRAYS
  unsigned int n = 4;
  int numbers[n] = {2, 7, 1, 9};
  int copy_numbers[n] = {2, 7, 1, 9};

  cout << "normal sort (using default order [crescent])" << endl;
  time.start();
  // IF YOU WANT TO USE vector class, replace numbers by numbers.begin() and numbers + SIZE by numbers.end()
  sort::bubble(numbers, numbers+n, true);
  time.stop();
  time.report("Elapsed time (sort)");

  cout << "custom sort (using a custom function [decreasing])" << endl;
  time.start();

  // IF YOU WANT TO USE vector class, check the above comment
  sort::bubble(copy_numbers, copy_numbers+n, smaller<int>, true);
  time.stop();
  time.report("Elapsed time (custom sort)");

  return 0;
}
