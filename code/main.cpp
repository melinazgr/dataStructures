#include <fstream>
#include <iostream>
#include <sstream>
#include <string> 
#include <vector> 
#include <iomanip>

#include "minheap.h"
#include "maxheap.h"
#include "heap.h"
#include "avl.h"
#include "hashtable.h"
#include "graph.h"

#include "driver.h"
#include "stopwatch.h"
#include "linkedList.h"

// include cpp files so as to compile main.cpp only
#include "minheap.cpp"
#include "maxheap.cpp"
#include "heap.cpp"
#include "avl.cpp"
#include "hashtable.cpp"
#include "graph.cpp"

const string CMD_BUILD = "BUILD";
const string CMD_INSERT = "INSERT";
const string CMD_GETSIZE = "GETSIZE";
const string CMD_FINDMIN = "FINDMIN";
const string CMD_FINDMAX = "FINDMAX";
const string CMD_DELETEMIN = "DELETEMIN";
const string CMD_DELETEMAX = "DELETEMAX";
const string CMD_DELETE = "DELETE";
const string CMD_SEARCH = "SEARCH";
const string CMD_COMPUTESHORTESTPATH = "COMPUTESHORTESTPATH";
const string CMD_COMPUTESPANNINGTREE = "COMPUTESPANNINGTREE";
const string CMD_FINDCONNECTEDCOMPONENTS = "FINDCONNECTEDCOMPONENTS";

const string CMD_MINHEAP = "MINHEAP";
const string CMD_MAXHEAP = "MAXHEAP";
const string CMD_AVLTREE = "AVLTREE";
const string CMD_GRAPH = "GRAPH";
const string CMD_HASHTABLE = "HASHTABLE";

//#define DEBUG_DS

using namespace std;

class commandParser
{
    private:
        vector <string> tokens;

    public:
        commandParser()
        {}

        // Takes a line like this "BUILD MINHEAP a.txt"
        // and produces three different tokens
        bool parse(string line)
        {
            tokens.clear(); // erases previous entries
            istringstream ss(line); // creates a string stream
            string token;

            // reads the words between spaces
            while(getline(ss, token, ' ')) 
            {
                tokens.push_back(token); 
            }

            return !tokens.empty();
        }

        // returns the token at index if present
        // otherwise returns an empty string
        const string &getToken(int index)
        {
            static const string empty_string("");

            if (tokens.size() <= index)
            {
                return empty_string;
            }

            return tokens.at(index);
        }
};

// prints on output text file the results of minheap/maxheap commands
void outputHeap(string dataStructure, string command, int data, ofstream &output, double time)
{
    if (command == CMD_BUILD || command == CMD_DELETEMIN || command == CMD_DELETEMAX)
    {
        output << command << " " << dataStructure;

        #ifdef DEBUG_DS
        for (int i = 0; i < data - 1; i++)
        {
            output << heap.getData(i) << " ";
        }
        #endif 
    }

    else if (command == CMD_INSERT)
    {
        output << command << " " << dataStructure << " " << data;
    }

    else if (command == CMD_FINDMIN || command == CMD_FINDMAX)
    {
        output << command << " " << dataStructure << " : " << data;
    }

    else if (command == CMD_GETSIZE)
    {
        output << command << " " << dataStructure << " : " << data;
    }

    output << "|| TIME : " << setprecision(10) << time << endl;
}

void outputHash(string command, int data, bool result, ofstream &output, double time)
{
    if (command == CMD_BUILD || command == CMD_INSERT)
    {
        output << command << " " << CMD_HASHTABLE;
    }
    
    else if (command == CMD_GETSIZE)
    {
        output << command << " " << CMD_HASHTABLE << " : " << data;
    }

    else if (command == CMD_SEARCH)
    {
        output << command << " " << CMD_HASHTABLE << " " << data << " : ";
        
        if (result) 
        {
            output <<"SUCCESS";
        }

        else
        {
            output << "FAILURE";
        }
    }

    output << "|| TIME : " << setprecision(10) << time << endl;
}

int main()
{
    minHeap minheap; 
    maxHeap maxheap; 
    hashTable hash;

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
            if (arg1 == CMD_BUILD)
            {
                if (arg2 == CMD_MINHEAP)
                {
                    minHeapDriver minHeapBuilder(minheap);
                    minHeapBuilder.readSingle(arg3);

                    outputHeap(CMD_MINHEAP, CMD_BUILD, 0, output, timer.elapsed());
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    maxHeapDriver maxHeapBuilder(maxheap);
                    maxHeapBuilder.readSingle(arg3);

                    outputHeap(CMD_MAXHEAP, CMD_BUILD, 0, output, timer.elapsed());
                }
                
                else if (arg2 == CMD_AVLTREE)
                {
                }
                
                else if (arg2 == CMD_HASHTABLE)
                {   
                    
                    hashDriver hashTableBuilder(hash);
                    hashTableBuilder.readSingle(arg3);

                    outputHash(CMD_BUILD, 0, false, output, timer.elapsed());  
                }

                else if (arg2 == CMD_GRAPH)
                {
                }
            }

            // INSERT command
            else if (arg1 == CMD_INSERT)
            {
                if (arg2 == CMD_MINHEAP)
                {
                    int data = stoi(arg3);
                    minheap.insert(data);

                    outputHeap(CMD_MINHEAP, CMD_INSERT, data, output, timer.elapsed()); 
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    int data = stoi(arg3);
                    maxheap.insert(data);

                    outputHeap(CMD_MAXHEAP, CMD_INSERT, data, output, timer.elapsed());  
                }
                
                else if (arg2 == CMD_AVLTREE)
                {
                }
                
                else if (arg2 == CMD_HASHTABLE)
                {
                    hash.insert(stoi(arg3));
                    outputHash(CMD_INSERT, 0, false, output, timer.elapsed());  
                }

                else if (arg2 == CMD_GRAPH)
                {
                }
            }

            // GETSIZE command
            else if (arg1 == CMD_GETSIZE)
            {
                if (arg2 == CMD_MINHEAP)
                {
                    int size = minheap.getSize();                       
                    outputHeap(CMD_MINHEAP, CMD_GETSIZE, size, output, timer.elapsed());   
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    int size = maxheap.getSize();
                    outputHeap(CMD_MAXHEAP, CMD_GETSIZE, size, output, timer.elapsed());   
                }
                
                else if (arg2 == CMD_AVLTREE)
                {
                }
                
                else if (arg2 == CMD_HASHTABLE)
                {
                    int size = hash.getSize();
                    outputHash(CMD_GETSIZE, size, false, output, timer.elapsed());
                }

                else if (arg2 == CMD_GRAPH)
                {
                }
            }

            // FINDMIN/FINMAX command
            else if (arg1 == CMD_FINDMIN || arg1 == CMD_FINDMAX)
            {
                if (arg2 == CMD_MINHEAP)
                {
                    int min = maxheap.findRoot();
                    outputHeap(CMD_MINHEAP, CMD_FINDMIN, min, output, timer.elapsed());    
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    int max = maxheap.findRoot();
                    outputHeap(CMD_MAXHEAP, CMD_FINDMAX, max, output, timer.elapsed());    
                }

                else if (arg2 == CMD_AVLTREE)
                {
                }
            }

            // DELETEMIN/DELETEMAX/DELETE command            
            else if (arg1 == CMD_DELETEMIN || arg1 == CMD_DELETEMAX || arg1 == CMD_DELETE)
            {
                if (arg2 == CMD_MINHEAP)
                {
                    maxheap.deleteRoot();
                    outputHeap(CMD_MINHEAP, CMD_DELETEMIN, 0, output, timer.elapsed());  
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    maxheap.deleteRoot();
                    outputHeap(CMD_MAXHEAP, CMD_DELETEMAX, 0, output, timer.elapsed());     
                }

                else if (arg2 == CMD_AVLTREE)
                {
                }

                else if (arg2 == CMD_GRAPH)
                {
                }
            }

            // SEARCH command
            else if (arg1 == CMD_SEARCH)
            {
                if (arg2 == CMD_AVLTREE)
                {
                }
                
                else if (arg2 == CMD_HASHTABLE)
                {
                    int data = stoi(arg3);
                    bool found = hash.search(data);

                    outputHash(CMD_SEARCH, data, found, output, timer.elapsed());
                }
            }

            // COMPUTESHORTESTPATH command
            else if (arg1 == CMD_COMPUTESHORTESTPATH)
            {
            }

            // COMPUTESPANNINGTREE command
            else if (arg1 == CMD_COMPUTESPANNINGTREE)
            {
            }
            
            // FINDCONNECTEDCOMPONENTS command
            else if (arg1 == CMD_FINDCONNECTEDCOMPONENTS)
            {
            }
        }
    }

    

    return 0;
}