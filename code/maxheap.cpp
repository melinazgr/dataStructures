#include "maxheap.h"

using namespace std;

// constructor: builds a heap of given size
maxHeap::maxHeap(int capacity)
{
    int size = 0;
    this->capacity = capacity;
    data = new int[capacity];
}

// destructor: frees the dynamically allocated memory
maxHeap::~maxHeap()
{
    delete [] data;
}

//returns the index of the parent of a node
int maxHeap::parent(int i)
{
    return (i - 1) / 2;
}

//returns the index of the left child of a node
int maxHeap::left(int i)
{
    return (2 * i + 1);
}

//returns the index of the right child of a node
int maxHeap::right(int i)
{
    return (2 * i + 2);
}

//returns the maximum element of the min heap
int maxHeap::findMax()
{
    return data[0];
}

// swaps two elements
void maxHeap::swap(int *x, int*y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// inserts a new number 'x' in the heap
void maxHeap::insert(int x)
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
    int i = size - 1; // the position of the new element
    data[i] = x;
    size++;

    // fix the max heap if it is violated by the insertion
    while(i != 0 && data[parent(i)] < data[i])
    {
        swap(&data[parent(i)], &data[i]);
        i = parent(i);
    } 
}

// deletes the maximum element of max heap (root)
void maxHeap::deleteMax()
{
    
}

// builds max heap
void maxHeap::buildMaxHeap(int size)
{
    
}