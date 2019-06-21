#pragma once

#include <ctime> 
#include <ratio>
#include <chrono>

using namespace std::chrono;

class stopwatch
{
    private:
        high_resolution_clock::time_point _start;
        high_resolution_clock::time_point _end;

    public:
        void start();

        void stop();

        double elapsed();
};