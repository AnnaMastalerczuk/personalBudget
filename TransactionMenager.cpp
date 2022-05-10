#include "TransactionMenager.h"

void TransactionMenager::addIncome(){

Income income = inputDataOfNewIncome();

    incomes.push_back(income);
    //usersFile.addUserToFile(user);

    cout << endl << "The income has been added successfully" << endl;
    system("pause");

}

Income TransactionMenager::inputDataOfNewIncome(){
Income income;
    income.setUserId(LOGGEDIN_USER_ID);

    /*do {
        cout << "Enter login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while (ifLoginExist(user.getLogin()) == true);

    cout << "Enter name: ";
    user.setName(AuxiliaryMethods::loadLine());
    cout << "Enter surname: ";
    user.setSurname(AuxiliaryMethods::loadLine());
    cout << "Enter password: ";
    user.setPassword(AuxiliaryMethods::loadLine());*/

    return income;

}
