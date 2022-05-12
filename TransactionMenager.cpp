#include "TransactionMenager.h"

void TransactionMenager::addIncome() {

    Income income = inputDataOfNewIncome();

    incomes.push_back(income);
    incomeFile.addIncomeToFile(income);

    cout << endl << "The income has been added successfully" << endl;
    system("pause");

}

Income TransactionMenager::inputDataOfNewIncome() {
    Income income;
    DateOperation dateOperation;

    string textString = "";
    income.setUserId(LOGGEDIN_USER_ID);
    income.setIncomeId(getNewIncomeId());

    income.setDate(dateOperation.chooseDate());

    income.setItem(income.showIncomeItemMenu());

    cout << "Enter amount: ";
    textString = AuxiliaryMethods::loadLine();
    income.setAmount(AuxiliaryMethods::conversionStringToDouble(AuxiliaryMethods::replaceCommaWithDot(textString)));

    //cout << income.getAmount() << endl;
    return income;

}

int TransactionMenager::getNewIncomeId() {
    if (incomes.empty() == true)
        return 1;
    else
        return incomes.back().getIncomeId() + 1;
}

void TransactionMenager::show(){
for (int i = 0; i < incomes.size(); i++){
    cout << incomes[i].getAmount() << endl;
}
}
