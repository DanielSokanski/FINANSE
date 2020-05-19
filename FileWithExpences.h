#ifndef FILEWITHEXPENCES_H
#define FILEWITHEXPENCES_H

#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "Expences.h"
#include "Markup.h"

class FileWithExpences {
    CMarkup xml;
    int lastExpenceId;
    int loadUserId();
    vector<Expences>expences;
public:
    FileWithExpences() {
        lastExpenceId = 0;
    };
    void addExpenceToFile(Expences expences);
    int getIdOfLastExpence();
    vector <Expences> loadExpencesOfLoggedInUser(int userId);
    int changeToNumber(string date);
};

#endif
