#pragma once

#include <iostream> 
#include <fstream>
#include <vector>
#include <string>

#include "hashTable.h"


using namespace std;

struct edge
{
    int to;
    int weight;

    edge(int to, int weight):to(to),weight(weight){}
};

bool operator == (const edge &e, const int &val);

typedef vector <edge> vertexAdjList;
typedef pair <int, int> pairInt;

// uses an adjacency list to represent the graph
// since every vertex can be a random integer number
// we use a map to assing a unique index to every vertex number 
class Graph
{
    private:
        int size; // number of vertices
        int edgeCount; 
        
        vector<vertexAdjList> vertices;
        
        hashTable vertexMap;
        
        // returns the unique index of a vertex
        //          -1 if not found
        int getVertexIndex(int key);

        // insert a vertex named key and returns the index
        // assumes the key is not already inserted
        int insertVertex(int key);

        void dfsInternal(vector<bool> &visited, int v);

        int dfsCount(vector<bool> &visited, int v, int &count);

        void bfs(int v);

        int bfsPath(int a, int b);

        int minDist(vector<int> dist, vector<bool> visited);

        int minVal(vector<int> queue);

        int prim(int v);

        int dijkstra(int a, int b);


    public:
        Graph();

        // inserts the edge (x, y) in the graph
        void insertEdge(int x, int y, int weight = 1);

        void insert(int x, int y);
        
        // deletes the edge (x, y)
        void deleteEdge(int x, int y);

        // returns the size of the graph
        int getSize(int &edges);

        // returns the number of the connected components
        int connectedComponents();

        int connectedComponents(vector<int> &component);

        void spanningTree(vector<int> &tree);

        int shortestPath(int a, int b);

        void print(ofstream &output);

        void print(const string &filename);
};