#include "minheap.h"

using namespace std;

// constructor: builds a heap of given size
minHeap::minHeap()
{
    int size = 0;
    this->capacity = capacity;
    data = new int[capacity];
}

// destructor: frees the dynamically allocated memory
minHeap::~minHeap()
{
    delete [] data;
}

//returns the index of the parent of a node
int minHeap::parent(int i)
{
    return (i - 1) / 2;
}

//returns the index of the left child of a node
int minHeap::left(int i)
{
    return (2 * i + 1);
}

//returns the index of the right child of a node
int minHeap::right(int i)
{
    return (2 * i + 2);
}

//returns the minimum element of the min heap
int minHeap::findMin()
{
    return data[0];
}

// swaps two elements
void minHeap::swap(int *x, int*y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
// inserts a new number 'x' in the heap
void minHeap::insert(int x)
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

    // fix the min heap if it is violated by the insertion
    while(i != 0 && data[parent(i)] > data[i])
    {
        swap(&data[parent(i)], &data[i]);
        i = parent(i);
    } 

}

// deletes the minimum element of min heap (root)
void minHeap::deleteMin()
{
    
}
