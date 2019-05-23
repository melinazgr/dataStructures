#pragma once 
#include <iostream>

using namespace std;

//class for min heap
class minHeap 
{
    private:
        int* data; // pointer to array of elemenets in the heap
        int capacity; // maximun possible size of the min heap
        int size; // current number of elements in the min heap

    public:
        // constructor
        minHeap(); 

        // destructor
        ~minHeap();

        //returns the index of the parent of a node
        int parent(int i);

        //returns the index of the left child of a node
        int left(int i);

        //returns the index of the right child of a node
        int right(int i);
        
        //returns the minimum element of the min heap
        int findMin();

        // inserts a new number 'x'
        void insert(int x);

        // deletes the minimum element of min heap (root)
        void deleteMin();
        
        // returns the size of the min heap
        int getSize();

        // swaps two elements
        void swap(int *x, int *y);
};