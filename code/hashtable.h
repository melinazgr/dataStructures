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
        hashTable():hashTable(101){}
        hashTable(int capacity);

        // destructor
        ~hashTable();

        int initialize(int capacity);

        // inserts an integer in the hash table
        void insert(int x);

        // inserts a given node in hash table
        void insert(linkedListNode* newNode);

        // returns the size of the hash table
        int getSize();

        int getCapacity();

        // returns the bucket of the key
        int hashKey(int x) {return x % capacity;}
        
        // returns  true if an integer is found
        //          alse otherwise
        bool search(int x);
};