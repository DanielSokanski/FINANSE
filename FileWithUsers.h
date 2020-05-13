#ifndef FILEWITHUSERS_H
#define FILEWITHUSERS_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "User.h"
#include "Markup.h"
#include "XMLFile.h"


using namespace std;

class FileWithUsers: public XMLFile
{
    CMarkup xml;
    const string USERS_FILE_NAME;
    vector<User> users;
    User getUserData();
public:
    FileWithUsers(string fileNameWithUsers): XMLFile(fileNameWithUsers){

    };
    vector <User> loadUsersFromFile();
    void addUserToFile(User user);
    void saveAllUsersToFile(vector<User> &users);
};


#endif
