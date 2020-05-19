#ifndef EXPENCEMANAGER_H
#define EXPENCEMANAGER_H

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
#include"FileWithExpences.h"
#include"Expences.h"
#include"User.h"
#include"XMLFile.h"

using namespace std;

class ExpenceManager {

    vector <Expences> expences;
    FileWithExpences fileWithExpences;
    const int LOGGED_IN_USER_ID;
    int loggedInUserId;
    void showExpencesData(Expences expence);

public:
    ExpenceManager (int loggedInUserId): LOGGED_IN_USER_ID (loggedInUserId) {
        expences = fileWithExpences.loadExpencesOfLoggedInUser(LOGGED_IN_USER_ID);
    };
    Expences enterNewExpence();
    void showAllExpences();
    void addExpence();
    string changeCommaToDotInAmount(string amount);
    int todaysDate();
    bool checkIfDateIsCorrect(string date);
    double getExpencesInCurrentMonth();
    char getSign();
    int getIdOfNewIncome();
    bool leapyear (int year);
    double getExpencesInPreviousMonth();
    double getExpencesFromCustomDates(string startDate, string endDate);
};


#endif
