#include "Income.h"

int Income::getIncomeId(){
return incomeId;
}

int Income::getUserId(){
return userId;
}

string Income::getDate(){
return date;
}

string Income::getItem(){
return item;
}

string Income::getAmount(){
return amount;
}

void Income::setIncomeId(int incomeId){
this->incomeId = incomeId;
}

void Income::setUserId(int userId){
this->userId = userId;
}

void Income::setDate(string date){
this->date = date;
}

void Income::setItem(string item){
this->item = item;
}

void Income::setAmount(string amount){
this->amount = amount;
}
