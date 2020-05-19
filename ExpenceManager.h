#ifndef EXPENCEMANAGER_H
#define EXPENCEMANAGER_H

#include<iostream>
#include<vector>

#include"UserManager.h"
#include"FileWithUsers.h"
#include"FileWithExpences.h"
#include"Expences.h"
#include"User.h"
#include"XMLFile.h"
#include "AuxiliaryFunctions.h"
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
    double getExpencesInCurrentMonth();
    double getExpencesInPreviousMonth();
    double getExpencesFromCustomDates(string startDate, string endDate);
};


#endif
