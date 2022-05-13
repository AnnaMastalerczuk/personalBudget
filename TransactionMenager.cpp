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

void TransactionMenager::show() {
    for (int i = 0; i < incomes.size(); i++) {
        cout << incomes[i].getAmount() << endl;
    }

        for (int i = 0; i < expenses.size(); i++) {
        cout << expenses[i].getAmount() << endl;
    }
}

void TransactionMenager::addExpense(){
Expense expense = inputDataOfNewExpense();

    expenses.push_back(expense);
    expenseFile.addExpenseToFile(expense);

    cout << endl << "The expense has been added successfully" << endl;
    system("pause");

}

Expense TransactionMenager::inputDataOfNewExpense() {
    Expense expense;
    DateOperation dateOperation;

    string textString = "";
    expense.setUserId(LOGGEDIN_USER_ID);
    expense.setExpenseId(getNewExpenseId());

    expense.setDate(dateOperation.chooseDate());

    expense.setItem(expense.showExpenseItemMenu());

    cout << "Enter amount: ";
    textString = AuxiliaryMethods::loadLine();
    expense.setAmount(AuxiliaryMethods::conversionStringToDouble(AuxiliaryMethods::replaceCommaWithDot(textString)));

    //cout << income.getAmount() << endl;
    return expense;
}

int TransactionMenager::getNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}
