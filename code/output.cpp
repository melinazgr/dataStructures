#include "output.h"
#include <iomanip>

//#define DEBUG_DS

const string output::CMD_BUILD = "BUILD";
const string output::CMD_INSERT = "INSERT";
const string output::CMD_GETSIZE = "GETSIZE";
const string output::CMD_FINDMIN = "FINDMIN";
const string output::CMD_FINDMAX = "FINDMAX";
const string output::CMD_DELETEMIN = "DELETEMIN";
const string output::CMD_DELETEMAX = "DELETEMAX";
const string output::CMD_DELETE = "DELETE";
const string output::CMD_SEARCH = "SEARCH";
const string output::CMD_COMPUTESHORTESTPATH = "COMPUTESHORTESTPATH";
const string output::CMD_COMPUTESPANNINGTREE = "COMPUTESPANNINGTREE";
const string output::CMD_FINDCONNECTEDCOMPONENTS = "FINDCONNECTEDCOMPONENTS";

const string output::CMD_MINHEAP = "MINHEAP";
const string output::CMD_MAXHEAP = "MAXHEAP";
const string output::CMD_AVLTREE = "AVLTREE";
const string output::CMD_GRAPH = "GRAPH";
const string output::CMD_HASHTABLE = "HASHTABLE";

// prints on output text file the results of minheap/maxheap commands
void output::outputHeap(string dataStructure, string command, int data, ofstream &output, double time)
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

void output::outputHash(string command, int data, bool result, ofstream &output, double time)
{
    if (command == CMD_BUILD)
    {
        output << command << " " << CMD_HASHTABLE;
    }

    else if (command == CMD_INSERT || command == CMD_GETSIZE)
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

void output::outputAvl(string command, int data, bool result, ofstream &output, double time)
{
    if (command == CMD_BUILD)
    {
        output << command << " " << CMD_AVLTREE;
    }
    
    else if (command == CMD_GETSIZE || command == CMD_INSERT || command == CMD_DELETE || command == CMD_FINDMIN )
    {
        output << command << " " << CMD_AVLTREE << " : " << data;
    }

    else if (command == CMD_SEARCH)
    {
        output << command << " " << CMD_AVLTREE << " " << data << " : ";
        
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