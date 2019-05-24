#pragma once 
#include <iostream>

using namespace std;

//class for min heap
class maxHeap
{
    private:
        int* data; // pointer to array of elemenets in the heap
        int capacity; // maximun possible size of the max heap
        int size; // current number of elements in the max heap

    public:
        // constructor
        maxHeap(); 

        // destructor
        ~maxHeap();
        
        // returns the size of the max heap
        int getSize();

        // returns index i of data array
        int getData(int i);

        //returns the index of the parent of a node
        int parent(int i);

        //returns the index of the left child of a node
        int left(int i);

        //returns the index of the right child of a node
        int right(int i);
        
        //returns the maximum element of the max heap
        int findMax();

        // inserts a new number 'x'
        void insert(int x);

        // deletes the maximum element of max heap (root)
        void deleteMax();

        // swaps two elements
        void swap(int *x, int *y);
};