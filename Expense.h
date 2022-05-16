#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>

#include "AuxiliaryMethods.h"

using namespace std;

class Expense{

int expenseId;
int userId;
int date;
string item;
string amount;

public:
    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    string getAmount();

    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(string amount);

    string showExpenseItemMenu();
};

#endif
