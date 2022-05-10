#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include "UserMenager.h"
#include "TransactionMenager.h"
#include <iostream>

using namespace std;

class PersonalBudget{

    UserMenager userMenager;
    TransactionMenager *transactionMenager;


public:
    PersonalBudget(string userFileName) : userMenager(userFileName){
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

};




#endif
