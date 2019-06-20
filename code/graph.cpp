#include "graph.h"

#include <queue> 
#include <algorithm>

bool operator == (const edge &e, const int &val)
{
    return e.to == val;
}

graph::graph()
{
    size = 0;
}

int graph::getVertexIndex(int key)
{
    map<int, int>::iterator itKey;

    itKey = keys.find(key);

    if(itKey != keys.end())
    {
        return itKey->second;
    }
    else
    {
        return -1;
    }
}

int graph::insertVertex(int key)
{
    vertexAdjList newList;
    keys.insert(std::pair<int, int>(key, size));
    vertices.push_back(newList);
    return size++;
}

void graph::insertEdge(int x, int y, int weight)
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
    }
}

void graph::deleteEdge(int x, int y)
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

int graph::getSize()
{
    return size;
}

void graph::dfsInternal(vector<bool> &visited, int v)
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

int graph::connectedComponents()
{
    // mark the current vertex as visited
    vector <bool> visited(size, false);

    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(visited[i] == false)
        {
            dfsInternal(visited, i);
            count++;
        }
    }
    
    return count;
}

int graph::prim(int v)
{
    vector <bool> visited(size, false);
    priority_queue <pairInt, vector <pairInt>, greater <pairInt>> q; 

    pairInt p;

    int mst = 0;

    q.push(make_pair(0, v));

    while(!q.empty())
    {
        p = q.top();
        q.pop();

        int u = p.second;

        if(visited[u])
        {
            continue;
        }

        visited[u] = true;
        mst += p.first;

        for(vertexAdjList::iterator itU = vertices[u].begin(); itU != vertices[u].end(); itU++)
        {
            int w = (*itU).to;
            if(!visited[w])
            {
                q.push(make_pair((*itU).weight, w));
            }
        }
    }

    return mst;
}

int graph::spanningTreePrim()
{
    return prim(0);
}

int graph::dijkstra(int x, int y)
{
    vector <bool> visited(size, false);
    vector <int> dist(size, INT_MAX);
    priority_queue <pairInt, vector <pairInt>, greater <pairInt>> q; 
    
    pairInt p;

    int a = getVertexIndex(x);
    int b = getVertexIndex(y);

    if(a == -1 || b == -1)
    {
        return -1;
    }

    dist[a] = 0;
    q.push(make_pair(0, a));

    while(!q.empty())
    {
        p = q.top();
        q.pop();

        int u = p.second;

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
                q.push(make_pair(dist[w], w));
            }
        }
    }

    return dist[b];
}

int graph::shortestPath(int a, int b)
{
    return dijkstra(a,b);
}

// output the format of graph based on  
// http://www.webgraphviz.com/
void graph::print(ofstream &output)
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

void graph::print(const string &filename)
{
    ofstream output;
    output.open(filename);

    print(output);
    output.close();
}

/*int graph::prim(int v)
{
    vector <bool> visited(size, false);
    vector <int> dist(size, INT_MAX);
    vector <int> predecessor(size, 0);

    int mst = 0;

    bool completed = false;

    dist[v] = 0;

    while(completed == false)
    {
        int u = minDist(dist, visited);

        if(u == -1)
        {
            break;
        }

        visited[u] = true;
    
        for(vertexAdjList::iterator itU = vertices[u].begin(); itU != vertices[u].end(); itU++)
        {
            int w = (*itU).to;
            if(!visited[w] && dist[w] > (*itU).weight)
            {
                dist[w] = (*itU).weight;
                predecessor[w] = u;
            }
        }

        completed = true;
        for(int i = 0; i < size; i++)
        {
            if(!visited[i])
            {
                completed = false;
                break;
            }
        }
    }
    
    int from = -1, to = 0;
    
    for(vector<int>::iterator itI = predecessor.begin(); itI != predecessor.end(); itI++, to++)
    {   
        from = (*itI);

        vertexAdjList::iterator e = std::find(vertices[from].begin(), vertices[from].end(), to);

        if(e == vertices[from].end() || from == to)
        {
            continue;
        }

        mst += (*e).weight;
       
        cout << from << " -> " << to << " weight "<< (*e).weight<< endl;

    }

    cout << " mst " << mst<< endl;
    return mst;

int graph::dfsCount(vector<bool> &visited, int v, int &count)
{   
    visited[v] = true;

    vertexAdjList::iterator itV;

    for(itV = vertices[v].begin(); itV != vertices[v].end(); itV++)
    {
        if(!visited[(*itV).to])
        {   
            count++;
            dfsCount(visited, (*itV).to, count);
        }
    }
    
    return count;
}
   

int graph::spanningTreeDfs()
{
    vector <bool> visited(size, false);

    int count = 0;

    for(int i = 0; i < size; i++)
    {
        if(visited[i] == false)
        {
            dfsCount(visited, i, count);
        }
    }

    vertexAdjList::iterator itV = vertices[0].begin();

    int mst = dfsCount(visited, (*itV).to, count);

    if(mst < size - 1)
    {
        return -1;
    }
    
    return mst;
}

int graph::minDist(vector<int> dist, vector<bool> visited)
{
    int min = INT_MAX;
    int min_index = -1;

    for(int i = 0; i < size; i++)
    {
        if(visited[i] == false && dist[i] < min)
        {
            min = dist[i];
            min_index = i;
        }
    }

    return min_index;
}
}*/