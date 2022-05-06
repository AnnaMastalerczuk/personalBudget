#include <iostream>

#include "PersonalBudget.h"

using namespace std;

int main()
{
    PersonalBudget personalBudget("users.xml");
    personalBudget.registerUser();
    //personalBudget.registerUser();

    personalBudget.logInUser();
    personalBudget.changePasswordOfLoggedUser();


    return 0;
}

#include "UserMenager.h"
int _main() {
//UserMenager userMenager;
//userMenager.registerUser();

return 0;
}
