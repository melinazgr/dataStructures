#include "graph.h"

graph::graph()
{
    size = 0;
    capacity = 100;
    adjList = new linkedList [capacity];
}

void graph::insertEdge(int x, int y)
{   
    map<int, int>::iterator itX;
    map<int, int>::iterator itY;

    itX = keys.find(x);
    itY = keys.find(y);

    if(itX == keys.end())
    {
        keys.insert(pair<int, int>(size, x));
        size++;
    }
    
    if(itY == keys.end())
    {
        keys.insert(pair<int, int>(size, y));
        size++;
    }

    adjList[itX->first].insert(y);
    adjList[itY->first].insert(x);
}

void graph::deleteEdge(int x, int y)
{   
    map<int, int>::iterator itX;
    map<int, int>::iterator itY;

    itX = keys.find(x);
    itY = keys.find(y);
    
    if(itX == keys.end() || adjList[itX->first].search(x) == false ||
       itY == keys.end() || adjList[itY->first].search(x) == false)
    {
        return;
    }

    else
    {
        adjList[itX->first].deleteNode(y);
        adjList[itY->first].deleteNode(x);
    }
    
    int sizeX = adjList[itX->first].getSize();
    int sizeY = adjList[itY->first].getSize();

    if(sizeX == 0)
    {
        size--;
    }

    if(sizeY == 0)
    {
        size--;
    }
}

int graph::getSize()
{
    return size;
}

void graph::dfs(int v, bool *visited)
{
    // mark the current vertex as visited
    visited[v] = true; // v = it->first

    map<int, int>::iterator itD;

    node* d = adjList[v].begin();

    while(adjList[v].traverse(d))
    {   
        itD = keys.find(d->data);

        if(!visited[itD->first])
        {
            dfs(itD->first, visited);
        }
    }
}

int graph::connectedComponents()
{
    bool *visited = new bool[size];

    for(int i = 0; i < size; i++) 
    {
        visited[i] = false; 
    }

    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(visited[i] == false)
        {
            dfs(i, visited);
            count++;
        }
    }
    
    return count;
}