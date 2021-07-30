/*
 * Test of UDGraphMatrix<T> class
 *
 * Status: TESTED Jul 29 2021
 */

#include <iostream>
#include <vector>
using namespace std;


#include "adas/ds/undirected_graph.hpp"
using namespace adas::ds;


#include "adas/utilities.hpp"
namespace au = adas::utilities;


int main(int argc, char const *argv[])
{
	UDGraphMatrix<int> graph = {1, 3, 5, 7};

	Matrix<double> mtx = graph.get_matrix();

	cout << "(init) Adjacency matrix: " << endl;
	cout << mtx << endl;

	cout << "Adding an edge between (1 and 5) vertices." << endl;
	graph.add_edge(1, 5);

	cout << "Adding an edge between (3 and 1) vertices with weight=10." << endl;
	graph.add_edge(3, 1, 10);

	cout << "(after adding an edge) Adjacency matrix: " << endl;
	cout << mtx << endl;

	vector<Vertex<int>> vertices = graph.get_vertices();
	au::print::to_stdout("Vertices:\n", vertices, "\n");

	return 0;
}