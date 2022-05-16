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
    textString = AuxiliaryMethods::addZerosAtTheEnd(AuxiliaryMethods::replaceCommaWithDot(textString));
    income.setAmount(textString);

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
    textString = AuxiliaryMethods::addZerosAtTheEnd(AuxiliaryMethods::replaceCommaWithDot(textString));
    expense.setAmount(textString);

    return expense;
}

int TransactionMenager::getNewExpenseId() {
    if (expenses.empty() == true)
        return 1;
    else
        return expenses.back().getExpenseId() + 1;
}

void TransactionMenager::showBalanceCurrentMonth() {
    DateOperation dateOperation;
    int startDate = dateOperation.getDateFirstDayOfCurrentMonth();
    int endDate = dateOperation.getDateLastDayOfCurrentMonth();

    showTransactionBalance(startDate, endDate);
}

void TransactionMenager::showBalancePreviousMonth(){
    DateOperation dateOperation;
    int startDate = dateOperation.getDateFirstDayOfPreviousMonth();
    int endDate = dateOperation.getDateLastDayOfPreviousMonth();

    showTransactionBalance(startDate, endDate);
}

void TransactionMenager::showBalanceSelectedPeriod(){
    DateOperation dateOperation;
    cout << "INPUT START DATE" << endl;
    int startDate = dateOperation.chooseDate();
    cout << "INPUT END DATE" << endl;
    int endDate = dateOperation.chooseDate();

    showTransactionBalance(startDate, endDate);

}

void TransactionMenager::showTransactionBalance(int startDate, int endDate) {
    sortIncomesTransaction();
    sortExpensesTransaction();
    double sumIncomes = 0;
    double sumExpenses = 0;
    bool isIncome = false;
    bool isExpense = false;

    DateOperation dateOperation;

    cout << "   >>> INCOMES <<<   " << endl;
    cout << "---------------------" << endl;
    for (vector <Income>::iterator itr = incomes.begin(); itr != incomes.end(); itr++){
        if (itr->getDate() >= startDate && itr->getDate() <= endDate){
            cout << dateOperation.convertDataFromIntToString(itr->getDate()) << endl;
            cout << itr->getAmount() << endl;
            cout << itr->getItem() << endl;
            cout << "---------------" << endl;
            sumIncomes += AuxiliaryMethods::conversionStringToDouble(itr->getAmount());
            isIncome = true;
        }
    }

    if (!isIncome){
        cout << "There is no incomes in this period" << endl;
    }

    cout << "   >>> EXPENSES <<<   " << endl;
    cout << "----------------------" << endl;
    for (vector <Expense>::iterator itr = expenses.begin(); itr != expenses.end(); itr++){
        if (itr->getDate() >= startDate && itr->getDate() <= endDate){
            cout << dateOperation.convertDataFromIntToString(itr->getDate()) << endl;
            cout << itr->getAmount() << endl;
            cout << itr->getItem() << endl;
            cout << "---------------" << endl;
            sumExpenses += AuxiliaryMethods::conversionStringToDouble(itr->getAmount());
            isExpense = true;
        }
    }

        if (!isExpense){
        cout << "There is no expenes in this period" << endl;
    }

    cout << endl << "Sum of incomes = " << sumIncomes << endl;
    cout << "Sum of expenses = " << sumExpenses << endl;
    cout << "Balance between incomes and expenses = " << sumIncomes - sumExpenses << endl;
    system("pause");
}

void TransactionMenager::sortIncomesTransaction() {
    sort(incomes.begin(), incomes.end(), [](Income& a, Income& b){
    return a.getDate() < b.getDate();
    });
}

void TransactionMenager::sortExpensesTransaction() {
    sort(expenses.begin(), expenses.end(), [](Expense& a, Expense& b){
    return a.getDate() < b.getDate();
    });
}

