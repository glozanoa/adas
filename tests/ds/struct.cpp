#include <iostream>
using namespace std;


template<typename T>
struct Interval
{
  T init;
  T end;
};

int main()
{
  Interval<int> x;
  x.init = 0;
  x.end = 1;

  cout << "x: (" << x.init << ", " << x.end << ")" << endl;

  return 0;
}
