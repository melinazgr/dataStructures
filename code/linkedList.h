#pragma once 

struct linkedListNode
{
    int key;
    int value;
    linkedListNode* next;
};

class linkedList
{
    protected:
        linkedListNode* head;
        int size;
        bool allowDuplicates;

    public:
        
        linkedList()
        {
            head = nullptr;
            size = 0;
            allowDuplicates = false;
        }

        linkedList(bool allowDuplicates)
        {
            head = nullptr;
            size = 0;

            this->allowDuplicates = allowDuplicates;
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

        virtual bool search(int key)
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

        virtual bool find(int key, int &value)
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
        
        virtual void insert(int key, int value = 0)
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