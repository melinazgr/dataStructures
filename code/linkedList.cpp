#include "linkedList.h"

linkedList::linkedList()
{
    head = nullptr;
    size = 0;
    allowDuplicates = false;
}

linkedList::linkedList(bool allowDuplicates)
{
    head = nullptr;
    size = 0;

    this->allowDuplicates = allowDuplicates;
}

linkedList::~linkedList()
{
    linkedListNode* temp = head;
    linkedListNode* prev;

    while (temp != nullptr)
    {
        prev = temp;
        temp = temp->next;
        delete prev;
    }
}

bool linkedList::search(int key)
{
    linkedListNode* temp = head;

    while (temp != nullptr)
    {   
        if(temp->key == key)
        {
            return true;
        }
        
        temp = temp->next;
    }

    return false;
}

bool linkedList::find(int key, int &value)
{
    linkedListNode* temp = head;

    while (temp != nullptr)
    {   
        if (temp->key == key)
        {
            value = temp->value;
            return true;
        }
        
        temp = temp->next;
    }

    return false;
}

void linkedList::insert(int key, int value)
{   
    bool found = search(key);
    
    if (found && !allowDuplicates)
    {
        return;
    }

    else
    {
        linkedListNode* newNode = new linkedListNode();
        newNode->key = key;
        newNode->value = value;
        newNode->next = head;
        head = newNode;

        size++;
    }
}

linkedListNode* linkedList::replaceHead(linkedListNode* newHead)
{
    linkedListNode* oldHead = head;
    head = newHead;

    return oldHead;
}

int linkedList::getSize()
{
    return size;
}