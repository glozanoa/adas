#include <iostream>
#include <vector>
using namespace std;

#include "adas/ds/queue.hpp"

int main()
{
  vector<int> keys = {15, 13, 9, 5, 12,  8,  7, 4, 0, 6, 2, 1};
  Queue<int> q = Queue<int>(keys, QT::MAX_PRIORITY);

  cout << "Maximum queue: " << q.maximum() << endl;
  q.extract_max();

  cout << "(after extract max) Maximum queue: " << q.maximum() << endl;

  q.insert(20);

  cout << "(after insert) Maximum queue: " << q.maximum() << endl;

  return 0;
}
