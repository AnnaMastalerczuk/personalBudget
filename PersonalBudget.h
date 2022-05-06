#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include "UserMenager.h"
#include <iostream>

using namespace std;

class PersonalBudget{

    UserMenager userMenager;

public:
    PersonalBudget(){};
    void registerUser();
    void logInUser();

};




#endif
