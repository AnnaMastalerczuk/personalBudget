#include "PersonalBudget.h"

void PersonalBudget::registerUser(){
userMenager.registerUser();
}

void PersonalBudget::logInUser(){
userMenager.logInUser();
if (userMenager.ifUserLoggedIn()) {
        transactionMenager = new TransactionMenager(userMenager.getLoggedUserId(), INCOME_FILE_NAME, EXPENSE_FILE_NAME);
    }
}

void PersonalBudget::logOutUser(){
userMenager.logOutUser();
}

bool PersonalBudget::ifUserLoggedIn(){
return userMenager.ifUserLoggedIn();
}

void PersonalBudget::changePasswordOfLoggedUser(){
userMenager.changePasswordOfLoggedUser();
}

void PersonalBudget::addIncome(){
transactionMenager->addIncome();
}

void PersonalBudget::addExpense(){
transactionMenager->addExpense();
}

void PersonalBudget::showBalanceCurrentMonth(){
transactionMenager->showBalanceCurrentMonth();
}

void PersonalBudget::showBalancePreviousMonth(){
transactionMenager->showBalancePreviousMonth();
}

void PersonalBudget::showBalanceSelectedPeriod(){
transactionMenager->showBalanceSelectedPeriod();
}

char PersonalBudget::showMainMenu(){
    char choice;

    system("cls");
    cout << "    >>> MAIN MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add new account" << endl;
    cout << "2. Log in" << endl;
    cout << "9. Exit" << endl;
    cout << "---------------------------" << endl;
    cout << "Your choice: ";
    cin >> choice;
    cin.sync();

    return choice;

}

char PersonalBudget::showUserMenu(){
    char choice;

    system("cls");
    cout << " >>> USER MENU <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add income" << endl;
    cout << "2. Add expense" << endl;
    cout << "3. Show balance - current month" << endl;
    cout << "4. Show balance - previous month" << endl;
    cout << "5. Show balance - selected period" << endl;
    cout << "6. Change password" << endl;
    cout << "7. Log out" << endl;
    cout << "---------------------------" << endl;
    cout << "You choice: ";
    cin >> choice;
    cin.sync();

    return choice;
}
