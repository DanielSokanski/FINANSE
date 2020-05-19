#ifndef AUXILIARYFUNCTIONS_H
#define AUXILIARYFUNCTIONS_H

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

class AuxiliaryFunctions {
public:
    static string changeCommaToDotInAmount(string amount);
    static string todaysDate();
    static bool checkIfDateIsCorrect(string date);
    static char getSign();
    static bool leapyear (int year);
    static int todaysDateInt(string dateInCorrectFormat);
};


#endif
