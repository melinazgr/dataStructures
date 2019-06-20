#include <fstream>
#include <string> 
#include <ctime> 
#include <ratio>
#include <chrono>
#include <iostream>

using namespace std;
using namespace std::chrono;

int main(int argc, char* argv[])
{
    ofstream output;
    output.open("singleNum.txt");

    high_resolution_clock::time_point t1 = high_resolution_clock::now();

    for(int i =  1000; i > 0; i--)
    {
        output << i*2 << endl;
    }
    high_resolution_clock::time_point t2 = high_resolution_clock::now();
    duration<double> time_span = duration_cast<duration<double>>(t2 - t1);
    cout<<time_span.count()<<endl;  
               
    output.close();
    return 0;
}