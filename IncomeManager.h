#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include<iostream>
#include<vector>
#include<windows.h>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <time.h>
#include <string>

#include"UserManager.h"
#include"FileWithUsers.h"
#include"FileWithIncomes.h"
#include"Incomes.h"
#include"User.h"
#include"XMLFile.h"

using namespace std;

class IncomeManager
{

    vector <Incomes>incomes;
    FileWithIncomes fileWithIncomes;
    const int LOGGED_IN_USER_ID;
    int loggedInUserId;
    void showIncomesData(Incomes income);

public:
    IncomeManager (int loggedInUserId)://string fileNameWithIncomes, int loggedInUserId) :
        //fileWithIncomes(fileNameWithIncomes),
         LOGGED_IN_USER_ID (loggedInUserId)
        {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUser(LOGGED_IN_USER_ID);
        };
    Incomes enterNewIncome();
    void showAllIncomes();
    void addIncomes();
    double changeCommaToDotInAmount(string amount);
    int todaysDate();
    bool checkIfDateIsCorrect(string date);
    //float getIncomesFromCurrentMonth();
    //float getIncomesFromPreviousMonth();
    //float getIncomesFromCustomDate();
    char getSign();
    int getIdOfNewIncome();
    bool leapyear (int year);

};


#endif
