/*
 * Queue template class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _QUEUE_H
#define _QUEUE_H

#include <iostream>
using namespace std;

#include "single_linked_node.hpp"

namespace adas::ds
{
    template<class T>
    class Queue
    {
    private:
        SLNode<T>* head;
        SLNode<T>* tail;
        unsigned int size;
        int max_size; //-1 : unlimited size

    public:
        Queue():head{nullptr}, tail{nullptr}, size{0}, max_size{-1} {};
        Queue(int queue_max_size);

        void put(SLNode<T>* node);
        void put(T value);
        SLNode<T>* get();
        SLNode<T>* _get_head(){return head;}
        int get_maximum_size(){return max_size;}

        friend ostream& operator<<(ostream& out, Queue<T> queue)
        {
            SLNode<T>* node = queue._get_head();
            while(node != nullptr)
            {
                out << *node << endl;
                node = node->get_next();
            }

            return out;
        }

    };

    template<class T>
    Queue<T>::Queue(int queue_max_size)
    :head{nullptr}, tail{nullptr}, size{0}
    {
        if (queue_max_size < 0)
            max_size = -1;
        else
            max_size = queue_max_size;
    }

    template<class T>
    void Queue<T>::put(SLNode<T>* node)
    {
        if (max_size != -1 & max_size < size+1)
            cerr << "Maximum size reached!" << endl;

        else
        {
            if(size == 0)
                head = tail = node;
            else
            {
                tail->set_next(node);
                node->set_next(nullptr);
                tail = node;
            }
        }

        size += 1;
    }

    template<class T>
    SLNode<T>* Queue<T>::get()
    {
        if(size == 0)
        {
            cerr << "Empty queue" << endl;
            return nullptr;
        }
        else
        {
            SLNode<T>* node = head;
            SLNode<T>* next2head = head->get_next();

            head = next2head;
            size -= 1;

            return node;
        }
    }

    template<class T>
    void Queue<T>::put(T value)
    {
        SLNode<T>* node = new SLNode<T>(value);
        this->put(node);
    }
}

#endif //_QUEUE_H
