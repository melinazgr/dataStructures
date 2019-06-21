#include "stopwatch.h"

void stopwatch::start()
{
    _start = _end = high_resolution_clock::now();
}

 void stopwatch::stop()
{
    _end = high_resolution_clock::now();
}

double stopwatch::elapsed()
{
    if (_start == _end)
    {
        stop();
    }

    duration<double> time_span = duration_cast<duration<double>>(_end - _start);
    return time_span.count();
}