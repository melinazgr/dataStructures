#include "priorityQueue.h"

void priorityQueue::push(int key, int value)
{
    queue.insert(key,value);
}

bool priorityQueue::getTop(int &key, int &value)
{
    linkedListNode* top = queue.getHead();

    if(top)
    {
        key = top->key;
        value = top->value;
        return true;
    }

    return false;
}

void priorityQueue::pop()
{
    queue.deleteHead();
}

bool priorityQueue::isEmpty()
{
    return queue.getHead() == nullptr;
}