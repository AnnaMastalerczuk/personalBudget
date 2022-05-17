#ifndef EXPENSEFILE_H
#define EXPENSEFILE_H

#include "Markup.h"
#include "Expense.h"
#include "XMLFile.h"
#include "DateOperation.h"

#include <iostream>
#include <vector>

using namespace std;

class ExpenseFile : XMLFile{
DateOperation dateOperation;

public:
    ExpenseFile(string expenseFileName) : XMLFile(expenseFileName){};
    void addExpenseToFile(Expense expense);
    vector <Expense> loadExpenseFromFile(int loggedInUserID);
    int getExpenseLastId();

};

#endif
