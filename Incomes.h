#ifndef INCOMES_H
#define INCOMES_H

#include<iostream>

using namespace std;

class Incomes
{
    int incomeId;
    int userId;
    int date;
    string item;
    double amount;
public:
    Incomes(int incomeId=0, int userId=0, int date = 0, string item = "", double amount = 0)
    {
        this -> incomeId = incomeId;
        this -> userId = userId;
        this -> date = date;
        this -> item = item;
        this -> amount = amount;
    }
    void setIncomeId(int newIncomeId);
    void setUserId(int newUserId);
    void setDate(int newDate);
    void setItem(string newItem);
    void setAmount(double newAmount);

    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();
};

#endif
