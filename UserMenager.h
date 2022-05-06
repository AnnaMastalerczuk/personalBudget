#ifndef USERMENAGER_H
#define USERMENAGER_H

#include "User.h"
#include "AuxiliaryMethods.h"
#include "UsersFile.h"

#include <iostream>
#include<vector>

using namespace std;

class UserMenager{

UsersFile usersFile;
vector <User> users;
int loggedUserId;

User inputDataOfNewUser();
int getNewUserId();
bool ifLoginExist(string login);

public:
    UserMenager(string userFileName) : usersFile(userFileName){
        users = usersFile.loadUsersFromFile();
    };
    //UserMenager(){};
    void registerUser();
    int logInUser();
    void logOutUser();
    void changePasswordOfLoggedUser();
};

#endif
