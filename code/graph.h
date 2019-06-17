#pragma once

#include <iostream> 
#include <fstream>
#include <map> 
#include <vector>
#include <string>

using namespace std;

typedef vector <int> vertexAdjList;

// uses an adjacency list to represent the graph
// since every vertex can be a random integer number
// we use a map to assing a unique index to every vertex number 
class graph
{
    private:
        int size; // size of graph
        
        vector<vertexAdjList> vertices;
        std::map<int, int> keys;
        
        // returns the unique index of a vertex
        //          -1 if not found
        int getVertexIndex(int key);

        // insert a vertex named key and returns the index
        // assumes the key is not already inserted
        int insertVertex(int key);

        void dfs(vector<bool> &visited, int v);

    public:
        graph();

        // inserts the edge (x, y) in the graph
        void insertEdge(int x, int y);
        
        // deletes the edge (x, y)
        void deleteEdge(int x, int y);

        // returns the size of the graph
        int getSize();

        // returns the number of the connected components
        int connectedComponents();

        void print(ofstream &output);

        void print(const string &filename);
};

