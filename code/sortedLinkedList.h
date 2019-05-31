#pragma once 

#include <iostream>

using namespace std;

struct linkedListNode
{
    int data;
    linkedListNode* next;
};

class sortedLinkedList
{
    private:
        linkedListNode* head;

    public:
        sortedLinkedList()
        {
            head = NULL;
        }

        ~sortedLinkedList()
        {
            linkedListNode* temp = head;  //use temp to not lose reference of the head 
            linkedListNode* prev;

            while (temp != NULL)
            {
                prev = temp;
                temp = temp->next;
                delete prev;
            }
        }

        bool search(int x)
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

        void insert(int x)
        {
            linkedListNode* p = head;
            linkedListNode* prevP = NULL;

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
        }
};