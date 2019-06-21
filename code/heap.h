#pragma once 

//class for heap
//diagram URL: http://yuml.me/diagram/scruffy/class/edit/[Heap|getSize;getData;findRoot;deleteRoot;insert;swap|parent;right;left]^-[minHeap], [Heap]^-[maxHeap]
class heap 
{
    protected:
        int* data; // pointer to array of elemenets in the heap
        int capacity; // maximun possible size of the min heap
        int size; // current number of elements in the min heap

        // fix the heap if it is violated
        virtual void adjustHeap(int i) = 0;

        virtual void heapify(int i) = 0;

    public:
        heap(); 
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

        bool isLeaf(int i);

        // inserts a new number 'x'
        void insert(int x);

        // deletes the root of the heap
        virtual void deleteRoot() = 0;
        
        // swaps two elements
        void swap(int &x, int &y); 
};