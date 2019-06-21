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
        
        linkedList();

        linkedList(bool allowDuplicates);

        ~linkedList();

        int getSize();

        virtual bool search(int key);

        virtual bool find(int key, int &value);
        
        virtual void insert(int key, int value = 0);

        linkedListNode* replaceHead(linkedListNode* newHead);
};