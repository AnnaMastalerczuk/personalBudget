#include "Income.h"

int Income::getIncomeId() {
    return incomeId;
}

int Income::getUserId() {
    return userId;
}

int Income::getDate() {
    return date;
}

string Income::getItem() {
    return item;
}

double Income::getAmount() {
    return amount;
}

void Income::setIncomeId(int incomeId) {
    this->incomeId = incomeId;
}

void Income::setUserId(int userId) {
    this->userId = userId;
}

void Income::setDate(int date) {
    this->date = date;
}

void Income::setItem(string item) {
    this->item = item;
}

void Income::setAmount(double amount) {
    this->amount = amount;
}

string Income::showIncomeItemMenu() {

    char choice = ' ';
    string text = " ";

    cout << "INCOME ITEM MENU" << endl;
    cout << "1. Salary" << endl;
    cout << "2. Interest on deposits" << endl;
    cout << "3. Sale on Allegro" << endl;
    cout << "4. Other. Input your own source of income." << endl;
    cout << "Choose source of income:" << endl;
    cin >> choice;
    cin.sync();
    //system ("cls");

    switch( choice ) {
    case '1':
        return text = "salary";
        break;

    case '2':
        text = "Interest on deposits";
        break;

    case '3':
        text = "sale on Allegro";
        break;

    case '4':
        cout << "Input your own source of income: ";
        text = AuxiliaryMethods::loadLine();
        break;

    default:
        cout << "Choose proper position" << endl;
        break;
    }

    return text;

}
