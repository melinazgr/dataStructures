#include <fstream>
#include <iostream>
#include <sstream>
#include <string> 
#include <vector> 

#include "minheap.h"
#include "maxheap.h"
#include "avl.h"
#include "hashtable.h"
#include "graph.h"

#include "commandParser.h"
#include "output.h"
#include "driver.h"
#include "stopwatch.h"

int main()
{
    minHeap minheap; 
    maxHeap maxheap; 
    hashTable hash;
    avlTree avl;
    Graph graph;

    vector<int> empty;

    ifstream commands;
    commands.open("commands.txt");
    
    ofstream output;
    output.open("output.txt");

    if (!commands.is_open())
    {
        cerr << "commands not open" <<endl;
        //TODO
        exit(1);
    }

    string line, word, filename;
        
    commandParser parser;
    stopwatch timer;

    while (!commands.eof())
    {   
        getline(commands, line);
        if (parser.parse(line))
        {
            const string arg1 = parser.getToken(0);
            const string arg2 = parser.getToken(1);
            const string arg3 = parser.getToken(2);
            const string arg4 = parser.getToken(3);

            #ifdef DEBUG_DS
            cout<< arg1 <<" " << arg2 << " " <<arg3<<endl;  
            #endif

            timer.start();

            // BUILD command
            if (arg1 == output::CMD_BUILD)
            {
                if (arg2 == output::CMD_MINHEAP)
                {
                    minHeapDriver minHeapBuilder(minheap);
                    minHeapBuilder.readSingle(arg3);

                    output::outputHeap(output::CMD_MINHEAP, output::CMD_BUILD, 0, output, timer.elapsed());
                }

                else if (arg2 == output::CMD_MAXHEAP)
                {
                    maxHeapDriver maxHeapBuilder(maxheap);
                    maxHeapBuilder.readSingle(arg3);

                    output::outputHeap(output::CMD_MAXHEAP, output::CMD_BUILD, 0, output, timer.elapsed());
                }
                
                else if (arg2 == output::CMD_AVLTREE)
                {
                    cout << "avl build" << endl;

                    avlDriver avlBuilder(avl);
                    avlBuilder.readSingle(arg3);
                    
                    output::outputAvl(output::CMD_BUILD, 0, false, output, timer.elapsed());
                }
                
                else if (arg2 == output::CMD_HASHTABLE)
                {   
                    hashDriver hashTableBuilder(hash);
                    hashTableBuilder.readSingle(arg3);

                    output::outputHash(output::CMD_BUILD, 0, false, output, timer.elapsed());  
                }

                else if (arg2 == output::CMD_GRAPH)
                {
                    graphDriver graphBuilder(graph);
                    graphBuilder.readPair(arg3);

                    output::outputGraph(output::CMD_BUILD, 0, 0, empty, output, timer.elapsed());
                }
            }

            // INSERT command
            else if (arg1 == output::CMD_INSERT)
            {
                if (arg2 == output::CMD_MINHEAP)
                {
                    int data = stoi(arg3);
                    minheap.insert(data);

                    output::outputHeap(output::CMD_MINHEAP, output::CMD_INSERT, data, output, timer.elapsed()); 
                }

                else if (arg2 == output::CMD_MAXHEAP)
                {
                    int data = stoi(arg3);
                    maxheap.insert(data);

                    output::outputHeap(output::CMD_MAXHEAP, output::CMD_INSERT, data, output, timer.elapsed());  
                }
                
                else if (arg2 == output::CMD_AVLTREE)
                {
                    cout << "insert build" << endl;

                    int data = stoi(arg3);
                    avl.insert(data);
                    output::outputAvl(output::CMD_INSERT, data, false, output, timer.elapsed());
                }
                
                else if (arg2 == output::CMD_HASHTABLE)
                {
                    int data = stoi(arg3);
                    hash.insert(data);
                    output::outputHash(output::CMD_INSERT, data, false, output, timer.elapsed());  
                }

                else if (arg2 == output::CMD_GRAPH)
                {   
                    int a = stoi(arg3);
                    int b = stoi(arg4);
                    graph.insert(a, b);

                    output::outputGraph(output::CMD_INSERT, a, b, empty, output, timer.elapsed());  
                }
            }

            // GETSIZE command
            else if (arg1 == output::CMD_GETSIZE)
            {
                if (arg2 == output::CMD_MINHEAP)
                {
                    int size = minheap.getSize();                       
                    output::outputHeap(output::CMD_MINHEAP, output::CMD_GETSIZE, size, output, timer.elapsed());   
                }

                else if (arg2 == output::CMD_MAXHEAP)
                {
                    int size = maxheap.getSize();
                    output::outputHeap(output::CMD_MAXHEAP, output::CMD_GETSIZE, size, output, timer.elapsed());   
                }
                
                else if (arg2 == output::CMD_AVLTREE)
                {
                    int size = avl.getSize();
                    output::outputAvl(output::CMD_GETSIZE, size, false, output, timer.elapsed());
                }
                
                else if (arg2 == output::CMD_HASHTABLE)
                {
                    int size = hash.getSize();
                    output::outputHash(output::CMD_GETSIZE, size, false, output, timer.elapsed());
                }

                else if (arg2 == output::CMD_GRAPH)
                {
                    int data = graph.getSize();

                    output::outputGraph(output::CMD_GETSIZE, data, 0, empty, output, timer.elapsed());
                }
            }

            // FINDMIN/FINMAX command
            else if (arg1 == output::CMD_FINDMIN || arg1 == output::CMD_FINDMAX)
            {
                if (arg2 == output::CMD_MINHEAP)
                {
                    int min = maxheap.findRoot();
                    output::outputHeap(output::CMD_MINHEAP, output::CMD_FINDMIN, min, output, timer.elapsed());    
                }

                else if (arg2 == output::CMD_MAXHEAP)
                {
                    int max = maxheap.findRoot();
                    output::outputHeap(output::CMD_MAXHEAP, output::CMD_FINDMAX, max, output, timer.elapsed());    
                }

                else if (arg2 == output::CMD_AVLTREE)
                {
                    int min = avl.findMin();

                    output::outputAvl(output::CMD_FINDMIN, min, false, output, timer.elapsed());
                }
            }

            // DELETEMIN/DELETEMAX/DELETE command            
            else if (arg1 == output::CMD_DELETEMIN || arg1 == output::CMD_DELETEMAX || arg1 == output::CMD_DELETE)
            {
                if (arg2 == output::CMD_MINHEAP)
                {
                    maxheap.deleteRoot();
                    output::outputHeap(output::CMD_MINHEAP, output::CMD_DELETEMIN, 0, output, timer.elapsed());  
                }

                else if (arg2 == output::CMD_MAXHEAP)
                {
                    maxheap.deleteRoot();
                    output::outputHeap(output::CMD_MAXHEAP, output::CMD_DELETEMAX, 0, output, timer.elapsed());     
                }

                else if (arg2 == output::CMD_AVLTREE)
                {
                    int data = stoi(arg3);
                    avl.deleteNode(data);

                    output::outputAvl(output::CMD_DELETE, 0, false, output, timer.elapsed());
                }

                else if (arg2 == output::CMD_GRAPH)
                {
                    int a = stoi(arg3);
                    int b = stoi(arg4);

                    graph.deleteEdge(a,b);

                    output::outputGraph(output::CMD_DELETE, a, b, empty, output, timer.elapsed());
                }
            }

            // SEARCH command
            else if (arg1 == output::CMD_SEARCH)
            {
                if (arg2 == output::CMD_AVLTREE)
                {
                    int data = stoi(arg3);
                    bool found = avl.search(data);

                    output::outputAvl(output::CMD_DELETE, data, found, output, timer.elapsed());
                }
                
                else if (arg2 == output::CMD_HASHTABLE)
                {
                    int data = stoi(arg3);
                    bool found = hash.search(data);

                    output::outputHash(output::CMD_SEARCH, data, found, output, timer.elapsed());
                }
            }

            // COMPUTESHORTESTPATH command
            else if (arg1 == output::CMD_COMPUTESHORTESTPATH)
            {
                int a = stoi(arg3);
                int b = stoi(arg4);

                int data = graph.shortestPath(a,b);

                output::outputGraph(output::CMD_COMPUTESHORTESTPATH, data, 0, empty, output, timer.elapsed());
            }

            // COMPUTESPANNINGTREE command
            else if (arg1 == output::CMD_COMPUTESPANNINGTREE)
            {
                vector<int> data;
                graph.spanningTree(data);

                output::outputGraph(output::CMD_COMPUTESPANNINGTREE, 0, 0, data, output, timer.elapsed());
            }
            
            // FINDCONNECTEDCOMPONENTS command
            else if (arg1 == output::CMD_FINDCONNECTEDCOMPONENTS)
            {
                int data = graph.connectedComponents();

                output::outputGraph(output::CMD_FINDCONNECTEDCOMPONENTS, data, 0, empty, output, timer.elapsed());
            }
        }
    }

    return 0;
}