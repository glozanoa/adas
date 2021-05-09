/*
 * Template graph class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _GRAPH_H
#define _GRAPH_H

#include <list>
#include <utility>

using namespace std;

typedef <typename T, template L>
class Edge
{
protected:
  T init;
  T end;
  L weight;

public:
  Edge(T init, T end, L weight) :init{init}, end{end}, weight{weight} {}

  pair<T, T> only_edge(){
    pait<T, T> only_edge(init, end);
    return only_edge;
  }

  friend ostream& operator<<(ostream& out, Edge<T, L> edge)
  {
    out << "Edge(init:" << init << ", end:" << end << ", weigth:" << weigth << ")";
    return out;
  }
};

typedef <template T, template L>
class Vertice
{
protected:
  T value;
  list<Edge<T, L>>* edges;

public:
  Vertice(T value): value{value}, edges{nullptr} {}
  Vertice(T value, list<Edge<T, L>>* edges): value{value}, edges{edges} {}
  list<Edges>* get_edges(){return edges;}
  T get_value(){return value;}
}

template<typename T, template L>
class Graph
{
protected:
  list<Vertice<T, L>> vertices;
  list<Egdes<T, L>>* egdes;

public:
  Graph(list<T> values, list<Egdes<T, L>>* graph_egdes)
    :edges{graph_egdes}
  {
    for(T value: values)
      {
        Vertice<T, L> vertice(value, edges);
        vertices.push_back(vertice);
      }
  }

  static bool is_edge(Edge<T, L> edge)
  /*
   * Check if edge belows to Graph's edges.
   *
   * Return true if edge is a Graph's edge and false if not.
   *
   */
  {
    // IMPLEMENT ME
    return true;
  }

  void add_edge(T init, T end, L weight)
  {
    // check if init and end below to the graph

    Edge<T, L> edge(init, end, weight);

    // CHECK THAT init and end ARE GRAPH's VERTICES
    // IF ANY ISN'T A GRAPH's VERTICE THROW AN EXCEPTION

    //check if edge below to edges and print a warning message
    // if edge belows to edges then replace else add to edges

    if(this->is_edge(edge))
      {
        cout << "Replacing edge by: " << edge << endl;
        // replace edge
      }
    else
      {
        cout << "Adding edge: " << edge << endl;
        edges->push_back(edge);
      }
  }
}

#endif //_GRAPH_H
