#pragma once 

#include "heap.h"

//class for min heap
class maxHeap : public heap
{
    public:
        // deletes the maximum element of max heap (root)
        virtual void deleteRoot();
        
        // fix the heap if it is violated
        virtual void adjustHeap(int i);

        // remake maxheap after deleting root
        virtual void heapify(int i);
};