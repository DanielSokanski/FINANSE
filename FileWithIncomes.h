#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Incomes.h"
#include "Markup.h"
//#include "XMLFile.h"



class FileWithIncomes
{
    //const string FILE_NAME_WITH_INCOMES;
    CMarkup xml;
    int lastIncomeId;
    int loadUserId();
    vector<Incomes>incomes;
public:
    FileWithIncomes()//(string fileName) : XMLFile(fileName)
        {
        lastIncomeId = 0;
        };
    void addIncomesToFile(Incomes incomes);
    int getIdOfLastIncome();
    vector <Incomes> loadIncomesOfLoggedInUser(int userId);
    int changeToNumber(string date);
};

#endif
