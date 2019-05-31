#include "minheap.h"

// inserts a new number 'x' in the heap
void minHeap::adjustHeap(int i)
{
    // fix the min heap if it is violated by the insertion
    while (i != 0 && data[parent(i)] > data[i])
    {
        swap(&data[parent(i)], &data[i]);
        i = parent(i);
    } 
}

// deletes the minimum element of min heap (root)
void minHeap::deleteRoot()
{
    // replace the deleted node (minimum element) with the farthest node
    data[0] = data[size - 1]; 
    int i = size;

    // fix the min heap if it is violated by the deletion
    while (i != 0 && data[parent(i)] > data[i])
    {
        swap (&data[parent(i)], &data[i]);
        i = parent(i);
    } 
}