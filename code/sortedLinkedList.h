#pragma once 

#include <iostream>
#include "linkedList.h"


class sortedLinkedList : public linkedList
{
    
    public:
        
        virtual bool search(int x)
        {
            linkedListNode* temp = head;  //use temp to not lose reference of the head 

            while (temp && (x > temp->data))
            {
                temp = temp->next;
            }

            if (temp && (x == temp->data))
            {
                return true;                
            }

            return false;
        }

        virtual void insert(int x)
        {
            linkedListNode* p = head;
            linkedListNode* prevP = nullptr;

            while (p && p->data < x)
            {  
                prevP = p; 
                p = p->next;
            }   

            if (p && p->data == x)
            {
                return;
            }

            linkedListNode* newNode = new linkedListNode();
            newNode->data = x;
            newNode->next = p;

            if (prevP)
            {
                prevP->next = newNode;
            }

            else
            {
                head = newNode;
            }

            size++;
        }

        void insert(linkedListNode* newNode)
        {
            linkedListNode* p = head;
            linkedListNode* prevP = nullptr;
            int x = newNode->data;

            while (p && p->data < x)
            {  
                prevP = p; 
                p = p->next;
            }   

            if (p && p->data == x)
            {
                return;
            }

            newNode->next = p;

            if (prevP)
            {
                prevP->next = newNode;
            }

            else
            {
                head = newNode;
            }

            size++;
        }
};