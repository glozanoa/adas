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

#endif //_TIMER_H
