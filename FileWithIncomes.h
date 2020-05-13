#ifndef FILEWITHINCOMES_H
#define FILEWITHINCOMES_H

#include <iostream>
#include <vector>
#include <cstdlib>
#include "Incomes.h"
#include "Markup.h"
#include "XMLFile.h"
#include "IncomeManager.h"


class FileWithIncomes: public XMLFile
{
    const string FILE_NAME_WITH_INCOMES;
    int lastIncomeId;
    int loadUserId();
public:
    FileWIthIncomes(string fileName) : XMLFile(fileName)
        {
        lastIncomeId = 0;
        };
    void addIncomesToFile(Incomes incomes);
    int getIdOfLastIncome();
    vector <Incomes> loadIncomesOfLoggedInUser(int userId);
    int changeToNumber(string date);
};

#endif
