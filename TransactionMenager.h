#ifndef TRANSACTIONMENAGER_H
#define TRANSACTIONMENAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxiliaryMethods.h"
#include "DateOperation.h"
#include "IncomeFile.h"

using namespace std;

class TransactionMenager{

    //Income income;
    IncomeFile incomeFile;

    const int LOGGEDIN_USER_ID;
    vector <Income> incomes;

    Income inputDataOfNewIncome();
    int getNewIncomeId();


public:
    TransactionMenager(int loggedUserId, string incomeFileName)
    : LOGGEDIN_USER_ID(loggedUserId), incomeFile(incomeFileName){
        //plikzAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci,ID_ZALOGOWANEGO_UZYTKOWNIKA);
        incomes = incomeFile.loadIncomeFromFile(LOGGEDIN_USER_ID);
    }

    void addIncome();
    void show();

};

#endif
