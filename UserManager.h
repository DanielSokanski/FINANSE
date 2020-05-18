#ifndef USERMANAGER_H
#define USERMANAGER_H

#include<iostream>
#include<vector>
#include<windows.h>
#include "FileWithUsers.h"
#include "User.h"
//#include "IncomeManager.h"
//#include "ExpenceManager.h"
using namespace std;

class UserManager
{
    int loggedInUserId;
    vector<User> users;
    User enterNewUserData();
    int getIdOfNewUser();
    bool doesLoginExist(string login);
    FileWithUsers fileWithUsers;


public:
    UserManager() //(string fileNameWithUsers):fileWithUsers(fileNameWithUsers)
    {
    loggedInUserId = 0;
    users = fileWithUsers.loadUsersFromFile();
    };

    //int loggedInUserId = 0;
    bool isUserLogedIn();
    char chooseOptionFromMainMenu();
    char getLine();
    char chooseOptionFromUserMenu();
    void registrationOfUser();
    void showAllUsers();
    void loginOfUser();
    string getWholeLine();
    //void compareExpencesToIncomesInCurrentMonth();
    //void compareExpencesToIncomesInPreviousMonth();
    //void compareExpencesToIncomesFromCustomDates();
    void changePassword();
    void logoutOfUser();
    int getIdOfLoggedInUser();

};




#endif
