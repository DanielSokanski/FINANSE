#ifndef YOURBUDGET_H
#define YOURBUDGET_H

#include<iostream>

#include "UserManager.h"
#include "IncomeManager.h"
#include "ExpenceManager.h"

using namespace std;

class YourBudget {
    UserManager userManager;
    IncomeManager *incomeManager;
    ExpenceManager *expenceManager;
public:
    YourBudget() {
        incomeManager = NULL;
        expenceManager = NULL;
    };
    ~YourBudget() {
        delete incomeManager;
        incomeManager = NULL;
        delete expenceManager;
        expenceManager = NULL;
    };
    bool isUserLogedIn();
    char chooseOptionFromMainMenu();
    char chooseOptionFromUserMenu();
    void registrationOfUser();
    void showAllUsers();
    void loginOfUser();
    void addIncome();
    void addExpence();
    void compareExpencesToIncomesInCurrentMonth();
    void compareExpencesToIncomesInPreviousMonth();
    void compareExpencesToIncomesFromCustomDates();
    void changePassword();
    void logoutOfUser();
    void showAllIncomes();
    void getIncomesInCurrentMonth();
    void getIncomesInPreviousMonth();
    void getIncomesFromCustomDates();
};
#endif
