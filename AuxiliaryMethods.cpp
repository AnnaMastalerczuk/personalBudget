#include "AuxiliaryMethods.h"

string AuxiliaryMethods::loadLine() {
    string userInput = "";
    getline(cin, userInput);
    return userInput;
}

string AuxiliaryMethods::replaceCommaWithDot(string textString) {

    char dot = '.';
    char comma = ',';
    char singleCharacter = ' ';

    for (int i = 0; i < textString.length(); i++) {
        singleCharacter = textString[i];
        if (singleCharacter == comma) {
            singleCharacter = dot;
            textString[i] = singleCharacter;
        }
    }

    return textString;
}

string AuxiliaryMethods::addZerosAtTheEnd(string text) {
    char dot = '.';
    char singleCharacter;
    int position = 0;
    int textLength = text.length();
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == dot) {
            position = i;
        }
    }

    if ((textLength - 1) - position == 1) {
        text = text.insert(textLength, "0");
    } else if (position == 0) {
        text = text.insert(textLength,".00");
    }

    return text;

}

double AuxiliaryMethods::conversionStringToDouble(string textString) {

    double numberDouble;
    istringstream iss(textString);
    iss >> numberDouble;

    return numberDouble;
}


int AuxiliaryMethods::conversionStringToInt(string textString) {

    int numberInt;
    istringstream iss(textString);
    iss >> numberInt;

    return numberInt;
}

string AuxiliaryMethods::conversionIntToString(int number) {
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}

string AuxiliaryMethods::conversionDoubleToString(double number) {
    stringstream ss;
    ss << number;
    string str = ss.str();
    return str;
}
