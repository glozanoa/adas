/*
 * Vertex class (graph vertex)
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _VERTEX_H
#define _VERTEX_H

#include <iostream>

namespace adas::ds
{
    template <class T>
    class Vertex
    {
    protected:
        T key;
        unsigned int degree;

    public:
        Vertex(T vertex_key): key{vertex_key}, degree{0} {}

        T get_key(){return key;}
        unsigned int get_degree(){return degree;}
        void set_degree(unsigned int vertex_degree){degree = vertex_degree;}

        friend std::ostream& operator<<(std::ostream& out, Vertex v)
        {
            out << "Vertex(key=" << v.get_key() << ", degree=" << v.get_degree() << ")"; 
            return out;
        }

        bool operator==(Vertex<T> v)
        {
            T vertex_key = v.get_key();
            unsigned int vertex_degree = v.get_degree();

            if (key == vertex_key && degree == vertex_degree)
                return true;

            return false;
        }
    };
}

#endif //_VERTEX_H
