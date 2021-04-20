#include <iostream>
using namespace std;

#include "../../include/sort.hpp"

int main()
{
  unsigned int n = 10;
  vector<int> shell = Sort<int>::shell_gap_sequences(n);

  cout << "shell grap sequence" << endl;
  print(shell);

  return 0;
}
