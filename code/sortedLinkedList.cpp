#include "sortedLinkedList.h"

bool sortedLinkedList::search(int key)
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

bool sortedLinkedList::find(int key, int &value)
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

void sortedLinkedList::insert(int key, int value = 0)
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

void sortedLinkedList::insert(linkedListNode* newNode)
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

linkedListNode* sortedLinkedList::getHead()
{
    return head;
}

void sortedLinkedList::deleteHead()
{
    linkedListNode* temp = head;

    if(head)
    {
        head = head->next;
        delete temp;
    }
}