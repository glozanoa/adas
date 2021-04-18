/*
 * Testing extern merge sorting algorithm
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */

#include <iostream>
#include <fstream>
using namespace std;

#include "../../include/sort.hpp"

int main()
{

  ifstream f1, f2;

  f1.open("n1.txt");
  f2.open("n2.txt");

  string mix = "mix.txt";

  Sort<int>::extern_merge(f1, f2, mix);

  ifstream mix_file = ifstream(mix);

  cout << "(Sorted numbers)" << endl;
  print_file(mix_file);

  return 0;
}
