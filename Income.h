#ifndef INCOME_H
#define INCOME_H

#include <iostream>

#include "AuxiliaryMethods.h"

using namespace std;

class Income{

int incomeId;
int userId;
string date;
string item;
double amount;

public:
    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    double getAmount();

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(string date);
    void setItem(string item);
    void setAmount(double amount);

    string showIncomeItemMenu();

};

#endif
