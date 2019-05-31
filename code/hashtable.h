#pragma once 

#include "sortedLinkedList.h"

class hashTable 
{
    private:
        sortedLinkedList* buckets; // bucket array
        int capacity; // size of bucket array
        int size; // size of hash table

    public:
        // constructors
        hashTable():hashTable(101){}
        hashTable(int capacity);

        // destructor
        ~hashTable();

        // inserts an integer in the hash table
        void insert(int x);

        // returns the size of the hash table
        int getSize();

        // returns the bucket of the key
        int hashKey(int x) {return x % capacity;}
        
        // returns  true if an integer is found
        //          alse otherwise
        bool search(int x);

        // returns the load factor of the hash table
        double getLoadFactor();
};