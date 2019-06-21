#pragma once

class priorityQueue 
{
    private:
        sortedLinkedList queue;

    public:
    
        priorityQueue():queue(true){}

        void push(int key, int value)
        {
            queue.insert(key,value);
        }

        bool getTop(int &key, int &value)
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

        void pop()
        {
            queue.deleteHead();
        }

        bool isEmpty()
        {
            return queue.getHead() == nullptr;
        }
};