#ifndef TRANSACTIONMENAGER_H
#define TRANSACTIONMENAGER_H

#include <iostream>
#include <vector>

#include "Income.h"
#include "AuxiliaryMethods.h"

using namespace std;

class TransactionMenager{

    Income income;

    const int LOGGEDIN_USER_ID;
    vector <Income> incomes;

    Income inputDataOfNewIncome();
    int getNewIncomeId();


public:
    TransactionMenager(int loggedUserId)
    : LOGGEDIN_USER_ID(loggedUserId){
        //plikzAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(adresaci,ID_ZALOGOWANEGO_UZYTKOWNIKA);
    }

    void addIncome();

};

#endif
