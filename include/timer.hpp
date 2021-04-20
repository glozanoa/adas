/*
 * Timer class
 *
 * Maintainer: glozanoa <glozanoa@uni.pe>
 */


#ifndef _TIMER_H
#define _TIMER_H

#include <iostream>
#include <ctime>
#include <string>
#include <chrono>

using namespace std::chrono;
using namespace std;

typedef struct TimePoints
{
  high_resolution_clock::time_point start;
  high_resolution_clock::time_point end;
}TimePoints;

class Timer
{
private:
  TimePoints tp;

public:
  Timer(){};
  void start();
  void restart();
  void stop();
  void report(string title); //REPORT FORMAT -> title : ELAPSED_TIME
};


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


#endif //_TIMER_H
