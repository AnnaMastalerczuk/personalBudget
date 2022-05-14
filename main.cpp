#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int _main()
{

    double suma = 55.55 +45.45;
    cout << suma << endl;
    PersonalBudget personalBudget("users.xml", "incomes.xml", "expense.xml");
    //personalBudget.registerUser();
    //personalBudget.registerUser();

    personalBudget.logInUser();
    personalBudget.addIncome();
    //personalBudget.changePasswordOfLoggedUser();


    return 0;
}

#include "UserMenager.h"
int register_main() {
//UserMenager userMenager;
//userMenager.registerUser();

return 0;
}

#include "TransactionMenager.h"
int main(){
TransactionMenager transactionMenager(1, "incomes.xml", "expense.xml");
//transactionMenager.addIncome();
//transactionMenager.show();
//transactionMenager.addExpense();
transactionMenager.showBalanceSelectedPeriod();

return 0;
}
