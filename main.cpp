#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expense.xml");
    char choice = ' ';

     while (true) {
        if (!personalBudget.ifUserLoggedIn()) {
            choice = personalBudget.showMainMenu();

            switch (choice) {
            case '1':
                personalBudget.registerUser();
                break;
            case '2':
                personalBudget.logInUser();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "There is no such option in the menu." << endl << endl;
                system("pause");
                break;
            }
        } else {
            choice = personalBudget.showUserMenu();

            switch (choice) {
            case '1':
                personalBudget.addIncome();
                break;
            case '2':
                personalBudget.addExpense();
                break;
            case '3':
                personalBudget.showBalanceCurrentMonth();
                break;
            case '4':
                personalBudget.showBalancePreviousMonth();
                break;
            case '5':
                personalBudget.showBalanceSelectedPeriod();
                break;
            case '6':
                personalBudget.changePasswordOfLoggedUser();
                break;
            case '7':
                personalBudget.logOutUser();
                break;
            }
        }
    }


    return 0;
}

#include "UserMenager.h"
int register_main() {
//UserMenager userMenager;
//userMenager.registerUser();

return 0;
}

#include "TransactionMenager.h"
int _main(){
TransactionMenager transactionMenager(1, "incomes.xml", "expense.xml");
//transactionMenager.addIncome();
//transactionMenager.show();
//transactionMenager.addExpense();
transactionMenager.addExpense();

return 0;
}
