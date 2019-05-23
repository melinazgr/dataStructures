#pragma once

#include "minheap.h"
#include "maxheap.h"
#include "avl.h"
#include "hashtable.h"
#include "graph.h"

class driver
{
    public:
        virtual void insert(int x, int y = 0) = 0;

        void readSingle(const string &filename)
        {
            //TODO

            insert(5);
        }

        void readPair(const string &filename)
        {
            //TODO

            insert(5,3);
        }
};

class minHeapDriver : public driver
{
    private:
        minHeap &minheap;
    public: 
        minHeapDriver(minHeap &_minheap):minheap(_minheap){}

        void insert(int x, int y)
        {
            minheap.insert(x);
        }
};

class avlDriver : public driver
{
    /*private:
        avlTree &avl;
    public: 
        avlDriver(avlTree &_avl, const string &filename):driver(filename),avl(_avl){}

        void insert(int x, int y)
        {
            avl.insert(x);
        }

       */
};