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
            head = nullptr;
            size = 0;
        }

        ~linkedList()
        {
            node* temp = head;  //use temp to not lose reference of the head 
            node* prev;

            while (temp != nullptr)
            {
                prev = temp;
                temp = temp->next;
                delete prev;
            }
        }

        bool search(int x)
        {
            node* temp = head;

            while (temp != NULL)
            {   
                if(temp->data == x)
                {
                    return true;
                }
                
                temp = temp->next;
            }

            return false;
        }
        
        void insert(int x)
        {   
            bool found = search(x);
            
            if (found)
            {
                return;
            }

            else
            {
                node* newNode = new node();
                newNode->data = x;
                newNode->next = head ;
                head = newNode;

                size++;
            }
        }

        void deleteNode(int x)
        {
            node* temp = head;

            while (temp->data != x)
            {                
                temp = temp->next;
            }

            // if the to-delete-node is the head
            if (temp == head)
            {
                temp->next = head;
            }

            // if the to-delete-node is not the head
            else
            {
                node* prev = head;

                while (prev->next != temp)
                {
                    prev = prev->next;
                }

                prev->next = temp->next;
            }

            delete temp;
        }

        node* traverse(node* d)
        {
            if(d)
            {
                d = d->next;
                return d->next;
            }
            else
            {
                return nullptr;
            }
        }

        int getSize()
        {
            return size;
        }

        node* begin()
        {
            return head;
        }
};