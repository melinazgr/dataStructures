#include "hashtable.h"

hashTable::hashTable(int capacity)
{
    size = 0;
    this->capacity = capacity;
    buckets = new sortedLinkedList[capacity];
}

hashTable::~hashTable()
{
    delete [] buckets;
}

int hashTable::getSize()
{
    return size;
}

double hashTable::getLoadFactor()
{
    return size / (double) capacity;
}

void hashTable::insert(int x)
{
    int h = hashKey(x);

    buckets[h].insert(x);
    size++;
}

bool hashTable::search(int x)
{
    int h = hashKey(x);

    return buckets[h].search(x);
}