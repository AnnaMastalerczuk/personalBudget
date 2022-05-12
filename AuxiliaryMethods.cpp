#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine()
{
    string userInput = "";
    getline(cin, userInput);
    return userInput;
}

string AuxiliaryMethods::replaceCommaWithDot(string textString){

    char dot = '.';
    char comma = ',';
    char singleCharacter = ' ';

    for (int i = 0; i < textString.length(); i++){
        singleCharacter = textString[i];
        if (singleCharacter == comma){
            singleCharacter = dot;
            textString[i] = singleCharacter;
        }
    }

    return textString;
}

double AuxiliaryMethods::conversionStringToDouble(string textString){

    double numberDouble;
    istringstream iss(textString);
    iss >> numberDouble;

    return numberDouble;
}

int AuxiliaryMethods::conversionStringToInt(string textString){

    int numberInt;
    istringstream iss(textString);
    iss >> numberInt;

    return numberInt;
}
