#include "FileWithUsers.h"


vector <User> FileWithUsers::loadUsersFromFile()
{
    User user;
    vector <User> users;

    bool fileExists = xml.Load( "users.xml" );
    xml.FindElem( "Users" );
    xml.IntoElem();
    while(xml.FindElem( "User" ))
    {
    user = getUserData();
    /*xml.IntoElem();
    xml.FindElem("UserId");
    user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("Login");
    user.setLogin(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Password");
    user.setPassword(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Name");
    user.setName(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Surname");
    user.setSurname(MCD_2PCSZ(xml.GetData()));*/
    users.push_back(user);
    xml.OutOfElem();
    }
    return users;
}
User FileWithUsers::getUserData()
{
    User user;
    xml.IntoElem();
    xml.FindElem("UserId");
    user.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
    xml.FindElem("Login");
    user.setLogin(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Password");
    user.setPassword(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Name");
    user.setName(MCD_2PCSZ(xml.GetData()));
    xml.FindElem("Surname");
    user.setSurname(MCD_2PCSZ(xml.GetData()));
    return user;
}

void FileWithUsers::addUserToFile(User user)
{

    bool fileExists = xml.Load( "users.xml" );

    if (!fileExists)
    {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    xml.AddElem("UserId", user.getUserId());
    xml.AddElem("Login", user.getLogin());
    xml.AddElem("Password", user.getPassword());
    xml.AddElem("Name", user.getName());
    xml.AddElem("Surname", user.getSurname());
    xml.Save("users.xml");


    xml.OutOfElem();
}
void FileWithUsers::saveAllUsersToFile(vector<User> &users)
{
    bool fileExists = xml.Load( "users.xml" );
    xml.RemoveElem();
    if (!fileExists)
        {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Users");
        }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("User");
    xml.IntoElem();
    for (int i=0; i<users.size(); i++){
        xml.AddElem("UserId", users[i].getUserId());
        xml.AddElem("Login", users[i].getLogin());
        xml.AddElem("Password", users[i].getPassword());
        xml.AddElem("Name", users[i].getName());
        xml.AddElem("Surname", users[i].getSurname());
        xml.OutOfElem();
    }
    xml.Save("users.xml");
}
