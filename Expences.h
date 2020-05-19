#ifndef EXPENCES_H
#define EXPENCES_H

#include<iostream>

using namespace std;

class Expences {
    int expenceId;
    int userId;
    string date;
    string item;
    string amount;
public:
    Expences(int expenceId=0, int userId=0, string date = "", string item = "", string amount = "") {
        this -> expenceId = expenceId;
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> amount = amount;
    }
    void setExpenceId(int newExpenceId);
    void setUserId(int newUserId);
    void setDate(string newDate);
    void setItem(string newItem);
    void setAmount(string newAmount);

    int getExpenceId();
    int getUserId();
    string getDate();
    string getItem();
    string getAmount();
};

#endif
