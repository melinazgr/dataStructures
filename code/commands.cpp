#include <fstream>

#include "commands.h"





using namespace std;

void build(string dataStructure, string filename)
{   
    ifstream file;
    file.open(filename);

    if(dataStructure == "MINHEAP")
    {
        minHeap a(10);
        a.buildMinHeap(10);
    }
}