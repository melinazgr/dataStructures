#pragma once 

#include "sortedLinkedList.h"

class hashTable 
{
    private:
        sortedLinkedList* buckets; // bucket array
        int capacity; // size of bucket array
        int size; // size of hash table

        // returns the load factor of the hash table
        double getLoadFactor();

    public:
        // constructors
        hashTable():hashTable(1001){}
        hashTable(int capacity);

        // destructor
        ~hashTable();

        // initialize capacity
        int initialize(int capacity);

        // inserts an integer in the hash table
        void insert(int key, int value = 0);

        // inserts a given node in hash table
        void insert(linkedListNode* newNode);

        // returns the size of the hash table
        int getSize();

        int getCapacity();

        // returns the bucket of the key
        int hashKey(int key) { return key % capacity; }
        
        // returns  true if an integer is found
        //          alse otherwise
        bool search(int key);

        bool find(int key, int &value);
};