#ifndef INCOMEMANAGER_H
#define INCOMEMANAGER_H

#include<iostream>
#include<vector>

#include"UserManager.h"
#include"FileWithUsers.h"
#include"FileWithIncomes.h"
#include"Incomes.h"
#include"User.h"
#include"XMLFile.h"
#include "AuxiliaryFunctions.h"
using namespace std;

class IncomeManager {
    vector <Incomes>incomes;
    FileWithIncomes fileWithIncomes;
    const int LOGGED_IN_USER_ID;
    int loggedInUserId;
    void showIncomesData(Incomes income);
public:
    IncomeManager (int loggedInUserId): LOGGED_IN_USER_ID (loggedInUserId) {
        incomes = fileWithIncomes.loadIncomesOfLoggedInUser(LOGGED_IN_USER_ID);
    };
    Incomes enterNewIncome();
    void showAllIncomes();
    void addIncomes();
    int getIdOfNewIncome();
    double getIncomesInCurrentMonth();
    double getIncomesInPreviousMonth();
    double getIncomesFromCustomDates(string startDate, string endDate);
};
#endif
