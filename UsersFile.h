#ifndef USERSFILE_H
#define USERSFILE_H

#include "User.h"
#include "Markup.h"

#include <iostream>
#include <vector>

using namespace std;

class UsersFile{

   public:

    void addUserToFile(User user);
    vector <User> loadUsersFromFile();
    void addAllUsersToFile(vector <User> users);

};

#endif
