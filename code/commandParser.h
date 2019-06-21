#pragma once

#include <vector>
#include <string> 
#include <sstream>

class commandParser
{
    private:
        vector <string> tokens;

    public:
        commandParser()
        {}

        // Takes a line like this "BUILD MINHEAP a.txt"
        // and produces three different tokens
        bool parse(string line);

        // returns the token at index if present
        // otherwise returns an empty string
        const string &getToken(int index);
};