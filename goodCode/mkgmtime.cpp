/*************************************************************************
    > File Name: mkgmtime.cpp
    > Author: pjg
    > Mail: 
    > Created Time: 2023/2/14 17:34:37
 ************************************************************************/

/*
 * from internet
 */

#include <time.h>

bool isLeapYear(short year) {
  if (year % 4 != 0)
    return false;
  if (year % 100 != 0)
    return true;
  return (year % 400) == 0;
}

time_t mkgmtime(short year, short month, short day, short hour, short minute,
                short second) {
  static const int SecondsPerMinute = 60;
  static const int SecondsPerHour = 3600;
  static const int SecondsPerDay = 86400;
  static const int DaysOfMonth[12] = {31, 28, 31, 30, 31, 30,
                                      31, 31, 30, 31, 30, 31};

  time_t secs = 0;
  for (short y = 1970; y < year; ++y)
    secs += (isLeapYear(y) ? 366 : 365) * SecondsPerDay;
  for (short m = 1; m < month; ++m) {
    secs += DaysOfMonth[m - 1] * SecondsPerDay;
    if (m == 2 && isLeapYear(year))
      secs += SecondsPerDay;
  }
  secs += (day - 1) * SecondsPerDay;
  secs += hour * SecondsPerHour;
  secs += minute * SecondsPerMinute;
  secs += second;
  return secs;
}
