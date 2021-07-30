/*
 * undirected graph classes: UDGraphMatrix<T>, ...
 *
 * Status: TESTED - date Jul 29 2021
 */

#ifndef _UDGRAPH_H
#define _UDGRAPH_H


#include <vector>
#include <algorithm>
#include <initializer_list>

#include "vertex.hpp"
#include "matrix.hpp"
#include "../exceptions/general.hpp"
using namespace adas::ds;


namespace adas::ds 
{

	template<class T>
	class UDGraphMatrix //Undirected graph with Adjacency Matrix as representation
	{
	protected:
		std::vector<Vertex<T>> vertices;
		Matrix<double> mtx;
	public:
		UDGraphMatrix();
		UDGraphMatrix(std::initializer_list<T> key_vertices);

		void add_edge(Vertex<T> init, Vertex<T> end, double weight);
		void add_edge(T init_key, T end_key); //default weight=1
		void add_edge(T init_key, T end_key, double weight);

		Matrix<double> get_matrix(){return mtx;}
		std::vector<Vertex<T>> get_vertices(){return vertices;}
	};

	template<class T>
	UDGraphMatrix<T>::UDGraphMatrix()
	{
		vertices = std::vector<Vertex<T>>();
		unsigned int size = 0;
		mtx = Matrix<double>(size, size, 0); // init the adyancency matrix with ceros
	}

	template<class T>
	UDGraphMatrix<T>::UDGraphMatrix(std::initializer_list<T> key_vertices)
	{
		vertices = std::vector<Vertex<T>>();
		for(T key : key_vertices)
		{
			Vertex<T> vertex = Vertex<T>(key);
			vertices.push_back(vertex);
		}		

		unsigned int size = vertices.size();
		mtx = Matrix<double>(size, size, 0); // init the adyancency matrix with ceros
	}


	template<class T>
	void UDGraphMatrix<T>::add_edge(Vertex<T> init, Vertex<T> end, double weight)
	{
		try
		{
			//check if init vertex is a graph's vertex 
			std::vector<Vertex<T>> it;

			it = std::find(vertices.begin(), vertices.end(), init);

			if(it == vertices.end())
			{
				cerr << "No vertex in the graph:" << init << endl;
				throw Exception("No vertex in the graph");	
			}

			unsigned int init_idx = std::distance(vertices.begin(), it);

			it = std::find(vertices.begin(), vertices.end(), end);

			if(it == vertices.end())
			{
				cerr << "No vertex in the graph:" << init << endl;
				throw Exception("No vertex in the graph");	
			}


			unsigned int end_idx = std::distance(vertices.begin(), it);

			mtx.set_value(init_idx, end_idx, weight);
			mtx.set_value(end_idx, init_idx, weight);

			//update indegree and outdegree of vertices
			unsigned int init_degree = init.get_outdegree();
			init.set_degree(init_degree+1);

			unsigned int end_degree = end.get_degree();
			end.set_degree(end_degree+1);
		
		}
		catch(exception& error)
		{
			cerr << error.what() << endl;
		}
	}

	template<class T>
	void UDGraphMatrix<T>::add_edge(T init_key, T end_key, double weight)
	{
		try
		{
			int init_idx = -1;
			int end_idx = -1;

			T key;
			for(int k=0; !(init_idx != -1 && end_idx != -1) && k<vertices.size(); k++)
			{
				key = vertices[k].get_key();
				if(key == init_key)
					init_idx = k;

				if(key == end_key)
					end_idx = k;
			}

			if(init_idx == -1 || end_idx == -1)
				throw Exception("No vertex in the graph");

			mtx.set_value(init_idx, end_idx, weight);
			mtx.set_value(end_idx, init_idx, weight);

			//update indegree and outdegree of vertices
			unsigned int init_degree = vertices[init_idx].get_degree();
			vertices[init_idx].set_degree(init_degree+1);

			unsigned int end_degree = vertices[end_idx].get_degree();
			vertices[end_idx].set_degree(end_degree+1);
		
		}
		catch(exception& error)
		{	
			cerr << error.what() << endl;
		}
	}

	template<class T>
	void UDGraphMatrix<T>::add_edge(T init_key, T end_key)
	{
		this->add_edge(init_key, end_key, 1);
	}

}

#endif //_UDGRAPH_H