#ifndef INCOME_H
#define INCOME_H

#include <iostream>

using namespace std;

class Income{

int incomeId;
int userId;
string date;
string item;
string amount;

public:
    int getIncomeId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(string date);
    void setItem(string item);
    void setAmount(string amount);

};

#endif
