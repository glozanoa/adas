#include "../include/timer.hpp"

void Timer::start()
{
  tp.start = high_resolution_clock::now();
}

void Timer::restart()
{
  this->start();
}

void Timer::stop()
{
  tp.end = high_resolution_clock::now();
}


void Timer::report(string title)
{
  duration<double> elapsed_time = duration_cast<duration<double>>(tp.end - tp.start);

  cout << title << " : " << elapsed_time.count() << endl;
}
