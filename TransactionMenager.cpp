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

void TransactionMenager::addExpense() {
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

void TransactionMenager::showBalanceCurrentMonth() {

    showTransactionBalance();


}

//1. posortowaæ wektor incomes i expenses wg daty (od najstarszej) i od najwiêkszej kwoty.
//2. wyswietl id, amount i data i item -> dla danych dat
//3. poka¿ sume incomes i expenses i roznice miedzy nimi

void TransactionMenager::showTransactionBalance() {
    DateOperation dateOperation;
    cout << "INCOMES:" << endl;
    for (int i = 0; i < incomes.size(); i++) {
        if (incomes[i].getDate() >= dateOperation.getDateFirstDayOfCurrentMonth()
                && incomes[i].getDate() <= AuxiliaryMethods::conversionStringToInt(dateOperation.removeDash(dateOperation.getCurrentDate()))) {
            //cout << incomes[i].getIncomeId() "----" dateOperation.convertDataFromIntToString(incomes[i].getDate()) "----" incomes[i].getAmount() << endl;
            cout << incomes[i].getIncomeId() << endl;
            cout << dateOperation.convertDataFromIntToString(incomes[i].getDate()) << endl;
            cout << incomes[i].getAmount() << endl;
            cout << incomes[i].getItem() << endl;
            cout << "---------------" << endl;
        }
    }

    cout << "EXPENSES:" << endl;
        for (int i = 0; i < expenses.size(); i++) {
        if (expenses[i].getDate() >= dateOperation.getDateFirstDayOfCurrentMonth()
                && expenses[i].getDate() <= AuxiliaryMethods::conversionStringToInt(dateOperation.removeDash(dateOperation.getCurrentDate()))) {
            //cout << incomes[i].getIncomeId() "----" dateOperation.convertDataFromIntToString(incomes[i].getDate()) "----" incomes[i].getAmount() << endl;
            cout << expenses[i].getExpenseId() << endl;
            cout << dateOperation.convertDataFromIntToString(expenses[i].getDate()) << endl;
            cout << expenses[i].getAmount() << endl;
            cout << expenses[i].getItem() << endl;
            cout << "---------------" << endl;
        }
    }
}

