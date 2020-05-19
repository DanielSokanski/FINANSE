#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <cstdlib>

#include "User.h"
#include "Markup.h"
#include "XMLFile.h"

using namespace std;

class FileWithUsers {
    CMarkup xml;
    vector<User> users;
    User getUserData();
public:
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void saveAllUsersToFile(vector<User> &users);
};

#endif
