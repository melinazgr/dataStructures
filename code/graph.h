#pragma once

#include <iostream> 
#include <iterator> 
#include <map> 

#include "linkedList.h"

class graph
{
    private:
        linkedList* adjList; // array of linked lists
        int capacity; // size of bucket array
        int size; // size of graph
        
        map<int, int> keys;



    public:
        // constructor
        graph();

        // distructor
        ~graph();

        // inserts the edge (x, y) in the graph
        void insertEdge(int x, int y);

        // deletes the edge (x, y)
        void deleteEdge(int x, int y);

        // returns the size of the graph
        int getSize();

        // returns the number of the connected components
        int connectedComponents();

        void dfs(int v, bool *visited);
};

