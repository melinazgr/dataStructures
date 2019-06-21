#pragma once 

#include <iostream>
#include "linkedList.h"


class sortedLinkedList : public linkedList
{
    
    public:
        sortedLinkedList(){}
        
        sortedLinkedList(bool allowDuplicates):linkedList(allowDuplicates){}

        virtual bool search(int key);

        virtual bool find(int key, int &value);

        virtual void insert(int key, int value = 0);

        void insert(linkedListNode* newNode);

        linkedListNode* getHead();

        void deleteHead();
};