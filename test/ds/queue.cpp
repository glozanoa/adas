/*
 * Testing Queue<T> class
 *
 * Status: TESTED - date Jul 29 2021
 */

#include <iostream>
using namespace std;

#include "adas/ds/queue.hpp"
using namespace adas::ds;

int main()
{
	Queue<int> q = Queue<int>();

	cout << "Maximum size: " << q.get_maximum_size() << endl;

	cout << "Inserting some values = [10, -1, 100] to the queue" << endl;
	q.put(10);
	q.put(-1);
	q.put(100);

	cout << "Printing the queue" << endl;
	cout << q << endl;

	cout << "Dequeue an element of the queue" << endl;
	SLNode<int>* node = q.get();
	cout << *node << endl;

	cout << "\nPrinting the queue (after a dequeue)" << endl;
	cout << q << endl;

	cout << "Dequeue 2 element of the queue" << endl;
	node = q.get();
	cout << *node << endl;
	node = q.get();
	cout << *node << endl;


	cout << "\nPrinting the queue" << endl;
	cout << q << endl;


	cout << "Finally, Dequeue other element of the queue" << endl;
	node = q.get(); // when the queue is empty, then return nullptr and print "Empty queue"
	if (node != nullptr)
		cout << *node << endl;


  return 0;
}
