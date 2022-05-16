#include "IncomeFile.h"

void IncomeFile::addIncomeToFile(Income income) {

    CMarkup xml;
    string amount = "";

    if (!xml.Load(getFileName())) {
        xml.AddElem("INCOMES");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("INCOME");
    xml.IntoElem();
    xml.AddElem("INCOMEID", income.getIncomeId());
    xml.AddElem("USERID", income.getUserId());
    xml.AddElem("DATE", dateOperation.convertDataFromIntToString(income.getDate()));
    xml.AddElem("ITEM", income.getItem());
    xml.AddElem("AMOUNT", income.getAmount());
    xml.OutOfElem();
    xml.Save(getFileName());

}

vector <Income> IncomeFile::loadIncomeFromFile(int loggedInUserID) {
    vector <Income> incomes;
    Income income;
    int date = 0;
    double amount = 0;

    CMarkup xml;

    xml.Load(getFileName());

    xml.FindElem("INCOMES");
    xml.IntoElem();

    while ( xml.FindElem("INCOME") ) {
        xml.IntoElem();
        xml.FindElem( "USERID");
        if(atoi(MCD_2PCSZ(xml.GetData())) == loggedInUserID) {
            xml.FindElem( "INCOMEID" );
            income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem( "DATE" );
            date = AuxiliaryMethods::conversionStringToInt(dateOperation.removeDash(xml.GetData()));
            income.setDate(date);
            xml.FindElem( "ITEM" );
            income.setItem(xml.GetData());
            xml.FindElem( "AMOUNT" );
            income.setAmount(xml.GetData());

            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}


