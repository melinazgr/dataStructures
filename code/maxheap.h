#pragma once 

#include "heap.h"

//class for min heap
class maxHeap : public heap
{
    public:
        // deletes the minimum element of max heap (root)
        virtual void deleteRoot();
        
        // fix the heap if it is violated
        virtual void adjustHeap(int i);
};