#pragma once 
#include <iostream>
#include "heap.h"

//class for min heap
class minHeap : public heap
{
    public:
        virtual void deleteRoot();

        virtual void adjustHeap(int i);
};