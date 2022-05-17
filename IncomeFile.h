#ifndef INCOMEFILE_H
#define INCOMEFILE_H

#include "Markup.h"
#include "Income.h"
#include "XMLFile.h"
#include "DateOperation.h"

#include <iostream>
#include <vector>

using namespace std;

class IncomeFile : XMLFile{
    DateOperation dateOperation;

public:
    IncomeFile(string incomeFileName) : XMLFile(incomeFileName){};
    void addIncomeToFile(Income income);
    vector <Income> loadIncomeFromFile(int loggedInUserID);
    int getIncomeLastId();
};

#endif
