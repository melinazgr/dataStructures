#pragma once 

struct node
{
    int data;
    node* next;
};

class linkedList
{
    private:
        node* head;
        int size;

    public:
        linkedList()
        {
            head = NULL;
            size = 0;
        }

        ~linkedList()
        {
            node* temp = head;  //use temp to not lose reference of the head 
            node* prev;

            while (temp != NULL)
            {
                prev = temp;
                temp = temp->next;
                delete prev;
            }
        }

        void insert(int x)
        {
            node* newNode = new node();
            newNode->data = x;
            newNode->next = head ;
            head = newNode;

            size++;
        }

        int getSize()
        {
            return size;
        }
};