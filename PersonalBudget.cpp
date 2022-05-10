#include "PersonalBudget.h"

void PersonalBudget::registerUser(){
userMenager.registerUser();
}

void PersonalBudget::logInUser(){
userMenager.logInUser();
if (userMenager.ifUserLoggedIn()) {
        transactionMenager = new TransactionMenager(userMenager.getLoggedUserId());
    }
}

void PersonalBudget::logOutUser(){
userMenager.logOutUser();
}

void PersonalBudget::changePasswordOfLoggedUser(){
userMenager.changePasswordOfLoggedUser();
}

void PersonalBudget::addIncome(){
transactionMenager->addIncome();
}
