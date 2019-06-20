#pragma once 

struct linkedListNode
{
    int data;
    linkedListNode* next;
};

class linkedList
{
    protected:
        linkedListNode* head;
        int size;

    public:
        
        linkedList()
        {
            head = nullptr;
            size = 0;
        }
        
        ~linkedList()
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

        virtual bool search(int x)
        {
            linkedListNode* temp = head;

            while (temp != nullptr)
            {   
                if(temp->data == x)
                {
                    return true;
                }
                
                temp = temp->next;
            }

            return false;
        }
        
        virtual void insert(int x)
        {   
            bool found = search(x);
            
            if (found)
            {
                return;
            }

            else
            {
                linkedListNode* newNode = new linkedListNode();
                newNode->data = x;
                newNode->next = head ;
                head = newNode;

                size++;
            }
        }

        linkedListNode* replaceHead(linkedListNode* newHead)
        {
            linkedListNode* oldHead = head;
            head = newHead;

            return oldHead;
        }

        int getSize()
        {
            return size;
        }
};