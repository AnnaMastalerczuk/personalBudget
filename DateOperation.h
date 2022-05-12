#ifndef DATEOPERATION_H
#define DATEOPERATION_H

#include <iostream>
#include <time.h>

#include "AuxiliaryMethods.h"
#include "Date.h"

using namespace std;

class DateOperation{

    string getCurrentDate();
    string setDateByUser();
    bool isDateCorrect(string date);
    Date divideDate(string date);
    int numberOfDaysInMonth(Date date);

public:
   int chooseDate();
   string convertDataFromIntToString(int data);
   string removeDash(string date);

};

#endif
