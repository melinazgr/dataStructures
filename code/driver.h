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
        virtual void insert(int x, int y = 0) = 0;

        // reads from a file with a single number on each line
        void readSingle(const string &filename)
        {
            ifstream data;
            data.open(filename);

           
            if(!data.is_open())
            {
                //TODO
                exit(1);
            }

            int n;

            while(!data.eof())
            {
                data >> n;
                insert(n);
            }
        }

        // reads from a file with two numbers on each line
        void readPair(const string &filename)
        {
            ifstream data;
            data.open(filename);

            if(!data.is_open())
            {
                //TODO
                exit(1);
            }

            int a, b;

            while(!data.eof())
            {
                data >> a >> b;
                insert(a,b);
            }
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

class maxHeapDriver : public driver
{
    private:
        maxHeap &maxheap;
    public: 
        maxHeapDriver(maxHeap &_maxheap):maxheap(_maxheap){}

        void insert(int x, int y)
        {
            maxheap.insert(x);
        }
};

class avlDriver : public driver
{
    private:
        avlTree &avl;
    public: 
        avlDriver(avlTree &_avl):avl(_avl){}

        void insert(int x, int y)
        {
            avl.insert(x);
        }
};

class hashDriver : public driver
{
    private:
        hashTable &hash;
    public: 
        hashDriver(hashTable &_hash):hash(_hash){}

        void insert(int x, int y)
        {
            hash.insert(x);
        }
};