#include "minheap.h"

// inserts a new number 'x' in the heap
void minHeap::adjustHeap(int i)
{
    // fix the min heap if it is violated by the insertion
     while(i != 0 && data[parent(i)] > data[i])
    {
        swap(data[parent(i)], data[i]);
        i = parent(i);
    } 
}

// deletes the minimum element of min heap (root)
void minHeap::deleteRoot()
{
    // replace the deleted node (minimum element) with the farthest node
    int i = size -1;
    data[0] = data[i]; 

    size--;
    heapify(0);
}

void minHeap::heapify(int i)
{
    if (!isLeaf(i))
    {
        if (data[i] > data[left(i)] || data[i] > data[right(i)])
        {
            if(data[left(i)] < data[right(i)])
            {
                swap(data[i], data[left(i)]);
                heapify(left(i));
            }

            else if(data[left(i)] > data[right(i)])
            {
                swap(data[i], data[right(i)]);
                heapify(right(i));
            }
        }
    }
}