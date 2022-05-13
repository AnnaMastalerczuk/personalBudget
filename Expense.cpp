#include "Expense.h"

int Expense::getExpenseId() {
    return expenseId;
}

int Expense::getUserId() {
    return userId;
}

int Expense::getDate() {
    return date;
}

string Expense::getItem() {
    return item;
}

double Expense::getAmount() {
    return amount;
}

void Expense::setExpenseId(int expenseId) {
    this->expenseId = expenseId;
}

void Expense::setUserId(int userId) {
    this->userId = userId;
}

void Expense::setDate(int date) {
    this->date = date;
}

void Expense::setItem(string item) {
    this->item = item;
}

void Expense::setAmount(double amount) {
    this->amount = amount;
}

string Expense::showExpenseItemMenu() {

    char choice = ' ';
    string text = " ";

    cout << "Expense ITEM MENU" << endl;
    cout << "1. Food" << endl;
    cout << "2. House and bills" << endl;
    cout << "3. Transport" << endl;
    cout << "4. Entertainment" << endl;
    cout << "5. Other. Input your own source of expense." << endl;
    cout << "Choose source of expense:" << endl;
    cin >> choice;
    cin.sync();
    //system ("cls");

    switch( choice ) {
    case '1':
        return text = "Food";
        break;

    case '2':
        text = "House and bills";
        break;

    case '3':
        text = "Transport";
        break;

    case '4':
        cout << "Entertainment";
        break;

    case '5':
        cout << "Input your own source of expense: ";
        text = AuxiliaryMethods::loadLine();
        break;

    default:
        cout << "Choose proper position" << endl;
        break;
    }

    return text;

}
