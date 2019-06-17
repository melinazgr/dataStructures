#include "graph.h"


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

void graph::insertEdge(int x, int y)
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

    vertices[idxX].push_back(idxY);
    vertices[idxY].push_back(idxX);
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

void graph::dfs(vector<bool> &visited, int v)
{   
    visited[v] = true;

    vertexAdjList::iterator itV;

    for(itV = vertices[v].begin(); itV != vertices[v].end(); itV++)
    {
        if(!visited[*itV])
        {
            dfs(visited, (*itV));
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
            dfs(visited, i);
            count++;
        }
    }
    
    return count;
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
            
           output <<  i << " -> " << (*itV) << endl;
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

