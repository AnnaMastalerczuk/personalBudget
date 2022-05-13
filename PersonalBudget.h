#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include "UserMenager.h"
#include "TransactionMenager.h"
#include <iostream>

using namespace std;

class PersonalBudget{

    UserMenager userMenager;
    TransactionMenager *transactionMenager;

    const string INCOME_FILE_NAME;
    const string EXPENSE_FILE_NAME;


public:
    PersonalBudget(string userFileName, string incomeFileName, string expenseFileName) : userMenager(userFileName), INCOME_FILE_NAME(incomeFileName),
    EXPENSE_FILE_NAME(expenseFileName){
    transactionMenager = NULL;
    };

    ~PersonalBudget() {
        delete transactionMenager;
        transactionMenager = NULL;
    }

    void registerUser();
    void logInUser();
    void logOutUser();
    void changePasswordOfLoggedUser();

    void addIncome();
    void addExpense();

};




#endif
