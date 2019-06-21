#include "driver.h"

// reads from a file with a single number on each line
void driver::readSingle(const string &filename)
{
    ifstream data;
    data.open(filename);
    
    if(!data.is_open())
    {
        //TODO
        exit(1);
    }

    int n;

    while(!data.eof())
    {
        data >> n;
        insert(n);
    }

    build();
}

// reads from a file with two numbers on each line
void driver::readPair(const string &filename)
{
    ifstream data;
    data.open(filename);

    if(!data.is_open())
    {
        //TODO
        exit(1);
    }

    int a, b;

    while(!data.eof())
    {
        data >> a >> b;
        insert(a,b);
    }

    build();
}

void hashDriver::build()
{
    int size = list.getSize();
    linkedListNode* head = list.replaceHead(nullptr);

    hash.initialize(size);

    for(linkedListNode* p = head; p;)
    {
        linkedListNode* temp = p->next;
        hash.insert(p);
        p = temp;
    }
}