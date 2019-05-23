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
#include "driver.h"

// include cpp files so as to compile main.cpp only
#include "minheap.cpp"
#include "maxheap.cpp"
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

using namespace std;

class commandParser
{
    private:
        vector <string> tokens;

    public:
        commandParser()
        {

        }

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

            if(tokens.size() <= index)
            {
                return empty_string;
            }

            return tokens.at(index);
        }
};

int main()
{
    minHeap minheap; 

    ifstream commands;
    commands.open("commands.txt");

    if(!commands)
    {
        //TODO
        exit(1);
    }

    int a, b;
    string line, word, filename;
    
    commandParser parser;

    while (getline(commands, line))
    {   
        if (parser.parse(line))
        {
            const string arg1 = parser.getToken(0);
            const string arg2 = parser.getToken(1);
            const string arg3 = parser.getToken(2);
            const string arg4 = parser.getToken(3);

        
            if(arg1 == CMD_BUILD)
            {
                if (arg2 == CMD_MINHEAP)
                {
                    cout<<"build minheap "<<arg3<<endl;  
                    minHeapDriver minHeapBuilder(minheap);
                    minHeapBuilder.readSingle(arg3);
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    cout<<"build MAXHEAP "<<arg3<<endl;   
                }
                
                else if (arg2 == CMD_AVLTREE)
                {
                    cout<<"build AVL "<<arg3<<endl;   
                }
                
                else if (arg2 == CMD_HASHTABLE)
                {
                    cout<<"build CMD_HASHTABLE  "<<arg3<<endl;   
                }

                else if (arg2 == CMD_GRAPH)
                {
                    cout<<"build CMD_GRAPH  "<<arg3<<endl;   
                }
            }

            else if (arg1 == CMD_INSERT)
            {
                if (arg2 == CMD_MINHEAP)
                {
                    cout<<"INSERT minheap "<<arg3<<endl;  
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    cout<<"INSERT  MAXHEAP "<<arg3<<endl;   
                }
                
                else if (arg2 == CMD_AVLTREE)
                {
                    cout<<"INSERT  AVL "<<arg3<<endl;   
                }
                
                else if (arg2 == CMD_HASHTABLE)
                {
                    cout<<"INSERT  CMD_HASHTABLE  "<<arg3<<endl;   
                }

                else if (arg2 == CMD_GRAPH)
                {
                    cout<<"INSERT  CMD_GRAPH  "<<arg3<<endl;   
                }
            }

            else if (arg1 == CMD_GETSIZE)
            {
                if (arg2 == CMD_MINHEAP)
                {
                    cout<<"GETSIZE minheap "<<arg3<<endl;  
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    cout<<"GETSIZE  MAXHEAP "<<arg3<<endl;   
                }
                
                else if (arg2 == CMD_AVLTREE)
                {
                    cout<<"GETSIZE AVL "<<arg3<<endl;   
                }
                
                else if (arg2 == CMD_HASHTABLE)
                {
                    cout<<"GETSIZE  CMD_HASHTABLE  "<<arg3<<endl;   
                }

                else if (arg2 == CMD_GRAPH)
                {
                    cout<<"GETSIZE CMD_GRAPH  "<<arg3<<endl;   
                }
            }

            else if (arg1 == CMD_FINDMIN || arg1 == CMD_FINDMAX)
            {
                 if (arg2 == CMD_MINHEAP)
                {
                    cout<<"FINDMIN minheap "<<arg3<<endl;  
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    cout<<"FINDMAX  MAXHEAP "<<arg3<<endl;   
                }

                else if (arg2 == CMD_AVLTREE)
                {
                    cout<<"FINDMIN AVL "<<arg3<<endl;   
                }
            }

            else if (arg1 == CMD_DELETEMIN || arg1 == CMD_DELETEMAX || arg1 == CMD_DELETE)
            {
                 if (arg2 == CMD_MINHEAP)
                {
                    cout<<"DELETEMIN minheap "<<arg3<<endl;  
                }

                else if (arg2 == CMD_MAXHEAP)
                {
                    cout<<"DELETEMAX MAXHEAP "<<arg3<<endl;   
                }

                else if (arg2 == CMD_AVLTREE)
                {
                    cout<<"DELETE AVL "<<arg3<<endl;   
                }

                else if (arg2 == CMD_GRAPH)
                {
                    cout<<"DELETE  CMD_GRAPH  "<<arg3<<endl;   
                }
            }

            else if (arg1 == CMD_SEARCH)
            {
                if (arg2 == CMD_AVLTREE)
                {
                    cout<<"SEARCH AVL "<<arg3<<endl;   
                }
                
                else if (arg2 == CMD_HASHTABLE)
                {
                    cout<<"SEARCH AVL "<<arg3<<endl;   
                }
            }
        }
    }

    return 0;
}