#ifndef USERMANAGER_H
#define USERMANAGER_H

#include<iostream>
#include<vector>
#include<windows.h>

#include "FileWithUsers.h"
#include "User.h"
#include "IncomeManager.h"
#include "ExpenceManager.h"

using namespace std;

class UserManager {
    int loggedInUserId;
    vector<User> users;
    User enterNewUserData();
    int getIdOfNewUser();
    bool doesLoginExist(string login);
    FileWithUsers fileWithUsers;
public:
    UserManager() {
        loggedInUserId = 0;
        users = fileWithUsers.loadUsersFromFile();
    };
    bool isUserLogedIn();
    char chooseOptionFromMainMenu();
    char getLine();
    char chooseOptionFromUserMenu();
    void registrationOfUser();
    void showAllUsers();
    void loginOfUser();
    string getWholeLine();
    void changePassword();
    void logoutOfUser();
    int getIdOfLoggedInUser();
};
#endif
