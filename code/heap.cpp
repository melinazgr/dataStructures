#include "heap.h"

using namespace std;

// constructor: builds a heap of given size
heap::heap()
{
    size = 0;
    capacity = 10;
    data = new int[capacity];
}

// destructor: frees the dynamically allocated memory
heap::~heap()
{
    delete [] data;
}

// returns the size of the heap
int heap::getSize()
{
    return size;
}

// returns index i of data array
int heap::getData(int i)
{
    return data[i];
}

//returns the index of the parent of a node
int heap::parent(int i)
{
    return (i - 1) / 2;
}

//returns the index of the left child of a node
int heap::left(int i)
{
    return (2 * i + 1);
}

//returns the index of the right child of a node
int heap::right(int i)
{
    return (2 * i + 2);
}

//returns the root of the heap
//(max or min element for maxheap or minheap accordingly)
int heap::findRoot()
{
    return data[0];
}

// swaps two elements
void heap::swap(int *x, int*y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// inserts a new number 'x'
void heap::insert(int x)
{
    // if the array is full create a new one with doubled size
    if(size == capacity)
    {
        int newCapacity = capacity * 2;
        int *temp = new int[newCapacity];

        for(int i = 0; i < capacity; i++)
        {
            temp[i] = data[i];
        }

        delete [] data;
        data = temp;
        capacity = newCapacity;
    }

    // insert the new element at the end 
    // and then increase the size of the heap
    int i = size; // the position of the new element
    data[i] = x;
    size++;

    adjustHeap(i);
}