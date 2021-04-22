#include <vector>
#include <iostream>
using namespace std;

int main()
{
  vector<int> x = {12, 29, 0, 33};
  int N = 10;
  vector<int>::iterator last = x.end();
  vector<int>::iterator beginm1 = x.begin();

  beginm1 = prev(beginm1);

  while(last != beginm1)
    {
      //N--;
      last--;
      cout << *last << endl;
    }

  return 0;
}
