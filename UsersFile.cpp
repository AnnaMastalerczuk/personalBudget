#include "UsersFile.h"

void UsersFile::addUserToFile(User user) {

    CMarkup xml;

    if (!xml.Load("users.xml")) {
        xml.AddElem("USERS");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("USER");
    xml.IntoElem();
    xml.AddElem("USERID", user.getUserId());
    xml.AddElem("LOGIN", user.getLogin());
    xml.AddElem("PASSWROD", user.getPassword());
    xml.AddElem("NAME", user.getName());
    xml.AddElem("SURNAME", user.getSurname());
    xml.OutOfElem();
    xml.Save("users.xml");

}

vector <User> UsersFile::loadUsersFromFile() {
    vector <User> users;
    User user;

    CMarkup xml;

    xml.Load("users.xml");

    xml.FindElem("USERS");
    xml.IntoElem();

    while ( xml.FindElem("USER") ) {
        xml.IntoElem();
        xml.FindElem( "USERID" );
        user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
        xml.FindElem( "LOGIN" );
        user.setLogin(xml.GetData());
        xml.FindElem( "PASSWORD" );
        user.setPassword(xml.GetData());
        xml.FindElem( "NAME" );
        user.setName(xml.GetData());
        xml.FindElem( "SURNAME" );
        user.setSurname(xml.GetData());
        xml.OutOfElem();

        users.push_back(user);

    }
return users;

}
