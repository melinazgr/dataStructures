#pragma once 

#include <iostream>
#include "linkedList.h"


class sortedLinkedList : public linkedList
{
    
    public:
        sortedLinkedList(){}
        
        sortedLinkedList(bool allowDuplicates):linkedList(allowDuplicates){}

        virtual bool search(int key)
        {
            linkedListNode* temp = head;

            while (temp && (key > temp->key))
            {
                temp = temp->next;
            }

            if (temp && (key == temp->key))
            {
                return true;                
            }

            return false;
        }

        virtual bool find(int key, int &value)
        {
            linkedListNode* temp = head;

            while (temp && (key > temp->key))
            {
                temp = temp->next;
            }

            if (temp && (key == temp->key))
            {
                value = temp->value;
                return true;                
            }

            return false;
        }

        virtual void insert(int key, int value = 0)
        {
            linkedListNode* p = head;
            linkedListNode* prevP = nullptr;

            while (p && p->key < key)
            {  
                prevP = p; 
                p = p->next;
            }   

            if (p && p->key == key && !allowDuplicates)
            {
                return;
            }

            linkedListNode* newNode = new linkedListNode();
            newNode->key = key;
            newNode->value = value;
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
            int key = newNode->key;

            while (p && p->key < key)
            {  
                prevP = p; 
                p = p->next;
            }   

            if (p && p->key == key && !allowDuplicates)
            {
                delete newNode;
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

        linkedListNode* getHead()
        {
            return head;
        }

        void deleteHead()
        {
            linkedListNode* temp = head;

            if(head)
            {
                head = head->next;
                delete temp;
            }
        }

};