#include "ExpenseFile.h"

void ExpenseFile::addExpenseToFile(Expense expense) {

    CMarkup xml;
    string amount = "";

    if (!xml.Load(getFileName())) {
        xml.AddElem("EXPENSES");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("EXPENSE");
    xml.IntoElem();
    xml.AddElem("EXPENSEID", expense.getExpenseId());
    xml.AddElem("USERID", expense.getUserId());
    xml.AddElem("DATE", dateOperation.convertDataFromIntToString(expense.getDate()));
    xml.AddElem("ITEM", expense.getItem());
    xml.AddElem("AMOUNT", expense.getAmount());
    xml.OutOfElem();
    xml.Save(getFileName());
}

vector <Expense> ExpenseFile::loadExpenseFromFile(int loggedInUserID) {
    vector <Expense> expenses;
    Expense expense;
    int date = 0;
    double amount = 0;

    CMarkup xml;

    xml.Load(getFileName());

    xml.FindElem("EXPENSES");
    xml.IntoElem();

    while ( xml.FindElem("EXPENSE") ) {
        xml.IntoElem();
        xml.FindElem( "USERID");
        if(atoi(MCD_2PCSZ(xml.GetData())) == loggedInUserID) {
            xml.FindElem( "EXPENSEID" );
            expense.setExpenseId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "DATE" );
            date = AuxiliaryMethods::conversionStringToInt(dateOperation.removeDash(xml.GetData()));
            expense.setDate(date);
            xml.FindElem( "ITEM" );
            expense.setItem(xml.GetData());
            xml.FindElem( "AMOUNT" );
            expense.setAmount(xml.GetData());

            expenses.push_back(expense);
        }
        xml.OutOfElem();
    }
    return expenses;
}
