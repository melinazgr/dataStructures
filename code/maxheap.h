#pragma once 
#include <iostream>
#include "heap.h"

//class for min heap
class maxHeap : public heap
{
    public:
        virtual void adjustHeap(int i);

        // deletes the minimum element of max heap (root)
        virtual void deleteRoot();
};