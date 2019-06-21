#pragma once

#include "sortedLinkedList.h"

class priorityQueue 
{
    private:
        sortedLinkedList queue;

    public:
    
        priorityQueue():queue(true){}

        void push(int key, int value);

        bool getTop(int &key, int &value);

        void pop();

        bool isEmpty();
};