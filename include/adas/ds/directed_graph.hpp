/*
 * directed graph classes
 *
 * Status: TESTED - date Jul 29 2021
 */


#ifndef _DGRAPH_H
#define _DGRAPH_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <initializer_list>

#include "vertex.hpp"
#include "matrix.hpp"
#include "../exceptions/general.hpp"
using namespace adas::ds;

namespace adas::ds
{
	template <class T>
	class DVertex : public Vertex<T> // vertex for directed graph
	{
	protected:
		unsigned int indegree;
		unsigned int outdegree;
	public:
		DVertex(T vertex_key):Vertex<T>(vertex_key), indegree{0}, outdegree{0} {}

		void set_indegree(unsigned int vertex_indegree){indegree = vertex_indegree;}
		void set_outdegree(unsigned int vertex_outdegree){outdegree = vertex_outdegree;}

		unsigned int get_indegree(){return indegree;}
		unsigned int get_outdegree(){return outdegree;}

	    friend std::ostream& operator<<(ostream& out, DVertex<T> v)
	    {
	        out << "Vertex(key=" << v.get_key() 
	        	<< ", indegree=" << v.get_indegree() 
	        	<< ", outdegree=" << v.get_outdegree() 
	        	<< ")"; 
	        return out;
	    }

	    bool operator==(DVertex<T> v)
	    {
			T vertex_key = v.get_key();
	        unsigned int vertex_indegree = v.get_indegree();
	        unsigned int vertex_outdegree = v.get_outdegree();

	        if (this->key == vertex_key && 
	        	this->indegree == vertex_indegree &&
	        	this->outdegree == vertex_outdegree)
	            return true;

	        return false;
	    }


	};


	template<class T>
	class DGraphMatrix //Directed graph with Adjacency Matrix as representation
	{
	protected:
		std::vector<DVertex<T>> vertices;
		Matrix<double> mtx;
	public:
		DGraphMatrix();
		DGraphMatrix(std::initializer_list<T> key_vertices);

		void add_edge(DVertex<T> init, DVertex<T> end, double weight);
		void add_edge(T init_key, T end_key); //default weight=1
		void add_edge(T init_key, T end_key, double weight);

		Matrix<double> get_matrix(){return mtx;}
		std::vector<DVertex<T>> get_vertices(){return vertices;}
	};

	template<class T>
	DGraphMatrix<T>::DGraphMatrix()
	{
		vertices = std::vector<DVertex<T>>();
		unsigned int size = 0;
		mtx = Matrix<double>(size, size, 0); // init the adyancency matrix with ceros
	}

	template<class T>
	DGraphMatrix<T>::DGraphMatrix(std::initializer_list<T> key_vertices)
	{
		vertices = std::vector<DVertex<T>>();
		for(T key : key_vertices)
		{
			DVertex<T> vertex = DVertex<T>(key);
			vertices.push_back(vertex);
		}		

		unsigned int size = vertices.size();
		mtx = Matrix<double>(size, size, 0); // init the adyancency matrix with ceros
	}


	template<class T>
	void DGraphMatrix<T>::add_edge(DVertex<T> init, DVertex<T> end, double weight)
	{
		try
		{
			//check if init vertex is a graph's vertex 
			std::vector<DVertex<T>> it;

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

			//update indegree and outdegree of vertices
			unsigned int init_outdegree = init.get_outdegree();
			init.set_outdegree(init_outdegree+1);

			unsigned int end_indegree = end.get_indegree();
			end.set_indegree(end_indegree+1);
		
		}
		catch(exception& error)
		{
			cerr << error.what() << endl;
		}
	}

	template<class T>
	void DGraphMatrix<T>::add_edge(T init_key, T end_key, double weight)
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

			//update indegree and outdegree of vertices
			unsigned int init_outdegree = vertices[init_idx].get_outdegree();
			vertices[init_idx].set_outdegree(init_outdegree+1);

			unsigned int end_indegree = vertices[end_idx].get_indegree();
			vertices[end_idx].set_indegree(end_indegree+1);
		
		}
		catch(exception& error)
		{	
			cerr << error.what() << endl;
		}
	}

	template<class T>
	void DGraphMatrix<T>::add_edge(T init_key, T end_key)
	{
		this->add_edge(init_key, end_key, 1);
	}

}


#endif //_DGRAPH_H