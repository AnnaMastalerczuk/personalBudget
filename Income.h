#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "AuxiliaryMethods.h"

using namespace std;

class Income{

int incomeId;
int userId;
int date;
string item;
string amount;

public:
    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    string getAmount();

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(string amount);

    string showIncomeItemMenu();

};

#endif
