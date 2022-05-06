#include "User.h"

void User::setUserId(int id) {
    this->userId = id;
}
void User::setLogin(string login) {
    this->login = login;
}
void User::setPassword(string password) {
    this->password = password;
}
void User::setName(string name) {
    this->name = name;
}
void User::setSurname(string surname) {
    this->surname = surname;
}

int User::getUserId() {
    return userId;
}
string User::getLogin() {
    return login;
}
string User::getPassword() {
    return password;
}
string User::getName() {
    return name;
}
string User::getSurname() {
    return surname;
}
