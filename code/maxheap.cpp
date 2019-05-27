#include "maxheap.h"

using namespace std;

// inserts a new number 'x' in the heap
void maxHeap::adjustHeap(int i)
{
    // fix the max heap if it is violated by the insertion
    while(i != 0 && data[parent(i)] < data[i])
    {
        swap(&data[parent(i)], &data[i]);
        i = parent(i);
    } 
}

// deletes the maximum element of max heap (root)
void maxHeap::deleteRoot()
{
    // replace the deleted node (minimum element) with the farthest node
    data[0] = data[size - 1]; 
    int i = size;

    // fix the max heap if it is violated by the deletion
    while(i != 0 && data[parent(i)] < data[i])
    {
        swap(&data[parent(i)], &data[i]);
        i = parent(i);
    } 
}