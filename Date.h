#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date{
 int year;
 int month;
 int day;

 public:
     void setYear(int year);
     void setMonth(int month);
     void setDay(int day);
     int getYear();
     int getMonth();
     int getDay();


};

#endif
