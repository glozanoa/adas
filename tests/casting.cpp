#include <iostream>
#include <string>
using namespace std;

#include "../include/cast.hpp"

int main()
{
  string v2cast = "123.13";

  cout << "string: " << v2cast << endl;
  double casted = str2<double>(v2cast);
  cout << "casted variable: " << casted << endl;

  return 0;
}
