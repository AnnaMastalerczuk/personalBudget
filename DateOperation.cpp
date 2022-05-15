#include "DateOperation.h"

int DateOperation::chooseDate() {
    string dateString = "";
    int dateInt = 0;
    char choice = ' ';

    cout << "Choose the date: " << endl;
    cout << "1. Current date" << endl;
    cout << "2. Enter the date yourself " << endl;
    cin >> choice;
    cin.sync();

    if (choice == '1') {
        dateString = getCurrentDate();
    } else if (choice == '2') {
        dateString = setDateByUser();
    }

    dateInt = AuxiliaryMethods::conversionStringToInt(removeDash(dateString));

    return dateInt;
}

string DateOperation::getCurrentDate() {
    time_t currentTime = time(0);
    struct tm* currentDataAndTime = localtime(&currentTime);
    char currentDataChar[11];
    strftime (currentDataChar,sizeof(currentDataChar),"%Y-%m-%d",currentDataAndTime);

    string currentData = currentDataChar;

    return currentData;
}

string DateOperation::setDateByUser() {
    bool ifDateCorrect = false;
    string userDate = "";

    do {
    cout << "Enter a date between 2000-01-01 and the last day of the current month in the correct format: rrrr-mm-dd (for example: 2004-04-05)" << endl;
    userDate = AuxiliaryMethods::loadLine();
    ifDateCorrect = isDateCorrect(userDate);
    } while (ifDateCorrect == false);

    return userDate;
}

bool DateOperation::isDateCorrect(string userDate) {
    Date date = divideDate(userDate);
    string currentDateString = getCurrentDate();
    Date currentDate = divideDate(currentDateString);
    bool isDateCorrect = false;
    int startingYear = 2000;
    int startingMonth = 1;
    int startingDay = 1;
    int numberOfDaysInUserMonth = numberOfDaysInMonth(date);

    if (date.getYear() >= startingYear && date.getMonth() > 0 && date.getMonth() < 13 && date.getDay() > 0 && date.getDay() <= numberOfDaysInUserMonth) {
        if (date.getYear() == currentDate.getYear() && date.getMonth() <= currentDate.getMonth() || date.getYear() < currentDate.getYear()){
            isDateCorrect = true;
        } else isDateCorrect = false;
    } else isDateCorrect = false;

return isDateCorrect;
}

Date DateOperation::divideDate(string userDate) {
    Date date;
    if (userDate.length() == 10) {

        date.setYear(atoi(userDate.substr(0,4).c_str()));
        date.setMonth(atoi(userDate.substr(5,2).c_str()));
        date.setDay(atoi(userDate.substr(8,2).c_str()));
    }

    return date;
}

int DateOperation::numberOfDaysInMonth(Date date) {

    int days = 0;

    if (date.getMonth() == 4 || date.getMonth() == 6 || date.getMonth() == 9 || date.getMonth() == 11)
        days = 30;
    else if (date.getMonth() == 2) {
        bool leapyear = (date.getYear() % 4 == 0 && date.getYear() % 100 != 0) || (date.getYear() % 400 == 0);

        if (leapyear == 0)
            days = 28;
        else
            days = 29;
    }
    else
        days = 31;
    return days;
}

string DateOperation::removeDash(string date){
string newDate = date.erase(4,1);
newDate = date.erase(6,1);

return newDate;
}

string DateOperation::convertDataFromIntToString(int dataInt){
string data = AuxiliaryMethods::conversionIntToString(dataInt);
data = data.insert(4,"-");
data = data.insert(7,"-");

return data;

}

int DateOperation::getDateFirstDayOfCurrentMonth(){
    string dataString = "";
    int dataInt = 0;
    dataString = removeDash(getCurrentDate());
    dataString = dataString.replace(6,2,"01");
    dataInt = AuxiliaryMethods::conversionStringToInt(dataString);

    return dataInt;
}

int DateOperation::getDateFirstDayOfPreviousMonth(){
    string dataString = "";
    int dataInt = 0;
    Date date;
    dataString = getCurrentDate();
    date = divideDate(dataString);
    if (date.getMonth() == 1){
        date.setYear(date.getYear()-1);
        date.setMonth(12);
    } else {
    date.setMonth(date.getMonth()-1);
    }

    if (date.getMonth() > 0 && date.getMonth() < 10){
        dataString = AuxiliaryMethods::conversionIntToString(date.getYear()) + "0" + AuxiliaryMethods::conversionIntToString(date.getMonth()) + "01";
    } else {
        dataString = AuxiliaryMethods::conversionIntToString(date.getYear()) + AuxiliaryMethods::conversionIntToString(date.getMonth()) + "01";
    }
    dataInt = AuxiliaryMethods::conversionStringToInt(dataString);

    return dataInt;
}

int DateOperation::getDateLastDayOfCurrentMonth(){
    string dataString = "";
    int dataInt = 0;
    int numberOfDays = 0;
    Date date;
    dataString = getCurrentDate();
    date = divideDate(dataString);
    numberOfDays = numberOfDaysInMonth(date);
    dataString = (removeDash(dataString)).replace(6,2,AuxiliaryMethods::conversionIntToString(numberOfDays));
    dataInt = AuxiliaryMethods::conversionStringToInt(dataString);

    return dataInt;

}

int DateOperation::getDateLastDayOfPreviousMonth(){
    string dataString = "";
    int dataInt = 0;
    int numberOfDays = 0;
    Date date;
    dataString = getCurrentDate();
    date = divideDate(dataString);
    if (date.getMonth() == 1){
        date.setYear(date.getYear()-1);
        date.setMonth(12);
    } else {
    date.setMonth(date.getMonth()-1);
    }

    numberOfDays = numberOfDaysInMonth(date);

    if (date.getMonth() > 0 && date.getMonth() < 10){
        dataString = AuxiliaryMethods::conversionIntToString(date.getYear()) + "0" + AuxiliaryMethods::conversionIntToString(date.getMonth()) + AuxiliaryMethods::conversionIntToString(numberOfDays);
    } else {
        dataString = AuxiliaryMethods::conversionIntToString(date.getYear()) + AuxiliaryMethods::conversionIntToString(date.getMonth()) + AuxiliaryMethods::conversionIntToString(numberOfDays);
    }

    dataInt = AuxiliaryMethods::conversionStringToInt(dataString);

    return dataInt;
}

