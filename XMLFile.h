#ifndef XMLFILE_H
#define XMLFILE_H

#include <iostream>

using namespace std;

class XMLFile {

const string FILE_NAME;

public:
    XMLFile(string userFileName) : FILE_NAME(userFileName) {};
    string getFileName();
};

#endif
