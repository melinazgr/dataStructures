#include "graph.h"
#include "priorityQueue.h"

#include <algorithm>

bool operator == (const edge &e, const int &val)
{
    return e.to == val;
}

Graph::Graph()
{
    size = 0;
    edgeCount = 0;
}

int Graph::getVertexIndex(int key)
{
    int value;
    
    if(vertexMap.find(key, value))
    {
        return value;
    }
    else
    {
        return -1;
    }
}

int Graph::insertVertex(int key)
{
    vertexAdjList newList;
    vertexMap.insert(key, size);
    vertices.push_back(newList);
    return size++;
}

void Graph::insertEdge(int x, int y, int weight)
{  
    int idxX = getVertexIndex(x);
    if(idxX == -1)
    {
        idxX = insertVertex(x);
    }

    int idxY = getVertexIndex(y);
    if(idxY == -1)
    {
        idxY = insertVertex(y);
    }
   
    edge edgeY(idxY, weight);
    vertices[idxX].push_back(edgeY);
    
    if(idxX != idxY)
    {
        edge edgeX(idxX, weight);
        vertices[idxY].push_back(edgeX);
        edgeCount++;
    }
}

void Graph::insert(int x, int y)
{
    insertEdge(x,y);
}

void Graph::deleteEdge(int x, int y)
{   
    int idxX = getVertexIndex(x);
    int idxY = getVertexIndex(y);

    if(idxX == -1 || idxY == -1)
    {
        return;
    }

    vertexAdjList::iterator itX;
    vertexAdjList::iterator itY;
    
    itX = std::find(vertices[idxX].begin(), vertices[idxX].end(), idxY);
    itY = std::find(vertices[idxY].begin(), vertices[idxY].end(), idxX);
    
    if(itX != vertices[idxX].end())
    {   
        vertices[idxX].erase(itX);
    }

    if(itY != vertices[idxY].end())
    {   
        vertices[idxY].erase(itY);
    }
}

int Graph::getSize(int &edges)
{
    edges = edgeCount;
    return size;
}

void Graph::dfsInternal(vector<bool> &visited, int v)
{   
    visited[v] = true;

    vertexAdjList::iterator itV;

    for(itV = vertices[v].begin(); itV != vertices[v].end(); itV++)
    {
        if(!visited[(*itV).to])
        {
            dfsInternal(visited, (*itV).to);
        }
    }
}

int Graph::connectedComponents()
{
    vector<int> component;
    return connectedComponents(component);
}

int Graph::connectedComponents(vector<int> &component)
{
    // mark the current vertex as visited
    vector <bool> visited(size, false);

    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(visited[i] == false)
        {   
            component.push_back(i);
            dfsInternal(visited, i);
            count++;
        }
    }
    
    return count;
}

int Graph::prim(int v)
{
    vector <bool> visited(size, false);
    vector <int> dist(size, INT_MAX);
    priorityQueue q;

    int mst = 0;

    dist[v] = 0;
    q.push(dist[v], v);

    while(!q.isEmpty())
    {
        int weight, u;
        q.getTop(weight, u);
        q.pop();

        if(visited[u])
        {
            continue;
        }

        visited[u] = true;
        //cout << "visiting: "<< u <<" weight: " << weight << endl;
        mst += weight;

        for(vertexAdjList::iterator itU = vertices[u].begin(); itU != vertices[u].end(); itU++)
        {
            int w = (*itU).to;
            if(!visited[w] && dist[w] > (*itU).weight)
            {
                dist[w] = (*itU).weight;
                q.push(dist[w], w);
            }
        }
    }

    return mst;
}

void Graph::spanningTree(vector<int> &tree)
{
    vector<int> component;
    connectedComponents(component);

    for(vector<int>::iterator itC = component.begin(); itC != component.end(); itC++)
    {
        tree.push_back(prim(*itC));
    }
}

int Graph::dijkstra(int x, int y)
{
    vector <bool> visited(size, false);
    vector <int> dist(size, INT_MAX);
    priorityQueue q;
    
    pairInt p;

    int a = getVertexIndex(x);
    int b = getVertexIndex(y);

    if(a == -1 || b == -1)
    {
        return -1;
    }

    dist[a] = 0;
    q.push(0,a);

    while(!q.isEmpty())
    {
        int weight, u;
        q.getTop(weight, u);
        q.pop();

        if(visited[u])
        {
            continue;
        }

        visited[u] = true;

        for(vertexAdjList::iterator itU = vertices[u].begin(); itU != vertices[u].end(); itU++)
        {
            int w = (*itU).to;
            if(dist[w] > dist[u] + (*itU).weight)
            {
                dist[w] =  dist[u] + (*itU).weight;
                q.push(dist[w], w);
            }
        }
    }

    return dist[b];
}

int Graph::shortestPath(int a, int b)
{
    return dijkstra(a,b);
}

// output the format of graph based on  
// http://www.webgraphviz.com/
void Graph::print(ofstream &output)
{   
    output << "Digraph G {" << endl << endl;
    for(int i = 0; i < size; i++)
    {
        for(vertexAdjList::iterator itV = vertices[i].begin(); itV != vertices[i].end(); itV++)
        {
           output <<  i << " -> " << (*itV).to << "[label=" << (*itV).weight <<"];"<< endl;
        }
    }

    output << endl << "}" << endl;
}

void Graph::print(const string &filename)
{
    ofstream output;
    output.open(filename);

    print(output);
    output.close();
}