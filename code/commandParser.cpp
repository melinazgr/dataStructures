#include "commandParser.h"

using namespace std;

// Takes a line like this "BUILD MINHEAP a.txt"
// and produces three different tokens
bool commandParser::parse(string line)
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
const string& commandParser::getToken(int index)
{
    static const string empty_string("");

    if (tokens.size() <= index)
    {
        return empty_string;
    }

    return tokens.at(index);
}