#include "UserMenager.h"

void UserMenager::registerUser() {
    User user = inputDataOfNewUser();

    users.push_back(user);
    usersFile.addUserToFile(user);

    cout << endl << "The account has been created successfully" << endl << endl;
    system("pause");

}

User UserMenager::inputDataOfNewUser() {
    User user;
    user.setUserId(getNewUserId());

    do {
        cout << "Enter login: ";
        user.setLogin(AuxiliaryMethods::loadLine());
    } while (ifLoginExist(user.getLogin()) == true);

    cout << "Enter name: ";
    user.setName(AuxiliaryMethods::loadLine());
    cout << "Enter surname: ";
    user.setSurname(AuxiliaryMethods::loadLine());
    cout << "Enter password: ";
    user.setPassword(AuxiliaryMethods::loadLine());

    return user;
}

int UserMenager::getNewUserId() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserMenager::ifLoginExist(string login) {
    for (int i = 0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "There is a user with this login." << endl;
            return true;
        }
    }
    return false;
}

int UserMenager::logInUser()
{
    User user;
    string login = "", password = "";

    cout << endl << "Enter login: ";
    login = AuxiliaryMethods::loadLine();

    vector <User>::iterator itr = users.begin();
    while (itr != users.end())
    {
        if (itr -> getLogin() == login)
        {
            for (int numberOfAttempts = 3; numberOfAttempts > 0; numberOfAttempts--)
            {
                cout << "Enter password. You have " << numberOfAttempts << " attempts remained: ";
                password = AuxiliaryMethods::loadLine();

                if (itr -> getPassword() == password)
                {
                    cout << endl << "You are logged in" << endl << endl;
                    system("pause");
                    loggedUserId = itr -> getUserId();
                    return loggedUserId;
                }
            }
            cout << "Password incorrectly entered 3 times." << endl;
            system("pause");
            return 0;
        }
        itr++;
    }
    cout << "There is no such user" << endl << endl;
    system("pause");
    return 0;
}
