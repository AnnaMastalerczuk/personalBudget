#ifndef TRANSACTIONMENAGER_H
#define TRANSACTIONMENAGER_H

#include <iostream>
#include <vector>

#include <algorithm>
#include <functional>

#include "Income.h"
#include "Expense.h"
#include "AuxiliaryMethods.h"
#include "DateOperation.h"
#include "IncomeFile.h"
#include "ExpenseFile.h"

using namespace std;

class TransactionMenager{

    //Income income;
    IncomeFile incomeFile;
    ExpenseFile expenseFile;

    const int LOGGEDIN_USER_ID;
    vector <Income> incomes;
    vector <Expense> expenses;

    Income inputDataOfNewIncome();
    int getNewIncomeId();
    Expense inputDataOfNewExpense();
    int getNewExpenseId();

    void showTransactionBalance(int startDate, int endDate);
    void sortIncomesTransaction();
    void sortExpensesTransaction();


public:
    TransactionMenager(int loggedUserId, string incomeFileName, string expenseFileName)
    : LOGGEDIN_USER_ID(loggedUserId), incomeFile(incomeFileName), expenseFile(expenseFileName){
        //plikzAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci,ID_ZALOGOWANEGO_UZYTKOWNIKA);
        incomes = incomeFile.loadIncomeFromFile(LOGGEDIN_USER_ID);
        expenses = expenseFile.loadExpenseFromFile(LOGGEDIN_USER_ID);
    }

    void addIncome();
    void addExpense();
    void show();
    void showBalanceCurrentMonth();
    void showBalancePreviousMonth();
    void showBalanceSelectedPeriod();

};

#endif
