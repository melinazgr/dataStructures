#pragma once 
#include <iostream>

//class for heap
class heap 
{
    protected:
        int* data; // pointer to array of elemenets in the heap
        int capacity; // maximun possible size of the min heap
        int size; // current number of elements in the min heap

        // fix the heap if it is violated
        virtual void adjustHeap(int i) = 0;

    public:
        // constructor
        heap(); 

        // destructor
        ~heap();

        // returns the size of the min heap
        int getSize();

        // returns index i of data array
        int getData(int i);
        
        // returns the index of the parent of a node
        int parent(int i);

        // returns the index of the left child of a node
        int left(int i);

        // returns the index of the right child of a node
        int right(int i);
        
        // returns the root of the heap
        int findRoot();

        // inserts a new number 'x'
        void insert(int x);

        // deletes the root of the heap
        virtual void deleteRoot() = 0;
        
        // swaps two elements
        void swap(int *x, int *y); 
};