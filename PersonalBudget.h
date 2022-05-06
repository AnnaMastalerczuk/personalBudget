#ifndef PERSONALBUDGET_H
#define PERSONALBUDGET_H

#include "UserMenager.h"
#include <iostream>

using namespace std;

class PersonalBudget{

    UserMenager userMenager;

public:
    PersonalBudget(string userFileName) : userMenager(userFileName){};
    void registerUser();
    void logInUser();
    void logOutUser();
    void changePasswordOfLoggedUser();

};




#endif
