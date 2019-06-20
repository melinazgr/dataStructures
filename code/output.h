#pragma once

#include <string> 
#include <fstream>

using namespace std;

class output
{
    public:
        static const string CMD_BUILD;
        static const string CMD_INSERT;
        static const string CMD_GETSIZE;
        static const string CMD_FINDMIN;
        static const string CMD_FINDMAX;
        static const string CMD_DELETEMIN;
        static const string CMD_DELETEMAX;
        static const string CMD_DELETE;
        static const string CMD_SEARCH;
        static const string CMD_COMPUTESHORTESTPATH;
        static const string CMD_COMPUTESPANNINGTREE;
        static const string CMD_FINDCONNECTEDCOMPONENTS;

        static const string CMD_MINHEAP;
        static const string CMD_MAXHEAP;
        static const string CMD_AVLTREE;
        static const string CMD_GRAPH;
        static const string CMD_HASHTABLE;

        static void outputHeap(string dataStructure, string command, int data, ofstream &output, double time);

        static void outputHash(string command, int data, bool result, ofstream &output, double time);

        static void outputAvl(string command, int data, bool result, ofstream &output, double time);

        static void outputGraph(string command, int data1, int data2, ofstream &output, double time);

};