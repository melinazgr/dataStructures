#pragma once

#include "minheap.h"
#include "maxheap.h"
#include "avl.h"
#include "hashtable.h"
#include "graph.h"

// class to read files with data to build each data structure
class driver
{
    public:
        virtual void insert(int first, int second = 0) = 0;
        virtual void build(){};
        
        // reads from a file with a single number on each line
        void readSingle(const string &filename);

        // reads from a file with two numbers on each line
        void readPair(const string &filename);
};

class minHeapDriver : public driver
{
    private:
        minHeap &minheap;
    public: 
        minHeapDriver(minHeap &_minheap):minheap(_minheap){}

        void insert(int x, int y){ minheap.insert(x); }
};

class maxHeapDriver : public driver
{
    private:
        maxHeap &maxheap;
    public: 
        maxHeapDriver(maxHeap &_maxheap):maxheap(_maxheap){}

        void insert(int x, int y){ maxheap.insert(x); }
};

class avlDriver : public driver
{
    private:
        avlTree &avl;
    public: 
        avlDriver(avlTree &_avl):avl(_avl){}

        void insert(int first, int second){ avl.insert(first); }
};

class hashDriver : public driver
{
    private:
        hashTable &hash;
        linkedList list;

    public: 
        hashDriver(hashTable &_hash):hash(_hash){}

        void insert(int x, int y) { list.insert(x); }

        virtual void build();
};

class graphDriver : public driver
{
    private:
        Graph &graph;
    public: 
        graphDriver(Graph &_graph):graph(_graph){}

        void insert(int first, int second){ graph.insert(first, second); }
};