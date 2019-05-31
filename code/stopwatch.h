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
        void start()
        {
            _start = _end = high_resolution_clock::now();
        }

        void stop()
        {
            _end = high_resolution_clock::now();
        }

        double elapsed()
        {
            if (_start == _end)
            {
                stop();
            }

            duration<double> time_span = duration_cast<duration<double>>(_end - _start);
            return time_span.count();
        }
};