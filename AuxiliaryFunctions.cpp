#include "AuxiliaryFunctions.h"

string AuxiliaryFunctions::todaysDate() {
    vector<int> date;
    time_t t = time(0);
    struct tm * now = localtime( & t );
    int todaysDateInt=0;
    date.push_back(now->tm_year + 1900);
    date.push_back(now->tm_mon+1);
    date.push_back(now->tm_mday);
    todaysDateInt = date[0]*10000+date[1]*100+date[2];

    date.clear();
    ostringstream dateInString;
    dateInString << todaysDateInt;
    string str = dateInString.str();
    string dateInCorrectFormat = "";
    for (int i=0; i<4; i++) {
        dateInCorrectFormat = dateInCorrectFormat + str[i];
    }
    dateInCorrectFormat = dateInCorrectFormat + "-";
    for (int i=0; i<2; i++) {
        dateInCorrectFormat = dateInCorrectFormat + str[i+4];
    }
    dateInCorrectFormat = dateInCorrectFormat + "-";
    for (int i=0; i<2; i++) {
        dateInCorrectFormat = dateInCorrectFormat + str[i+6];
    }
    return dateInCorrectFormat;
}

int AuxiliaryFunctions::todaysDateInt(string dateInCorrectFormat)
{
    string dateInPureString = "";
    for (int i=0; i<dateInCorrectFormat.length(); i++) {
    if (dateInCorrectFormat[i] != '-')
        dateInPureString = dateInPureString + dateInCorrectFormat[i];
    }

    int dateInInt = atoi(dateInPureString.c_str());
    return dateInInt;
}

char AuxiliaryFunctions::getSign() {
    string income = "";
    char sign  = {0};
    while (true) {
        getline(cin, income);

        if (income.length() == 1) {
            sign = income[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return sign;
}

string AuxiliaryFunctions::changeCommaToDotInAmount(string amount) {
    string amountWithDot="";
    double correctAmount = 0;
    for (int i=0; i<amount.length(); i++) {
        if (amount[i]==',')
            amountWithDot = amountWithDot + '.';
        else
            amountWithDot = amountWithDot + amount[i];
    }
    return amountWithDot;
}

bool AuxiliaryFunctions::checkIfDateIsCorrect(string date) {

    int day, month, year;
    string seperating = "";
    vector<string> tempDate;
    for (int i=0; i<date.length(); i++) {
        if(date[i]!='-') {
            seperating = seperating + date[i];
        } else {
            tempDate.push_back(seperating);
            seperating = "";
        }
    }
    tempDate.push_back(seperating);
    year = atoi(tempDate[0].c_str());

    if ((year < 2000) || (year > 2021)) {
        cout<< "Nieprawidlowy rok. Wpisz ponownie: ";
        return false;
    }
    month = atoi(tempDate[1].c_str());

    if (month > 12) {
        cout << "Nieprawidlowy miesiac. Wpisz ponownie: ";
        return false;
    }
    day = atoi(tempDate[2].c_str());

    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
        if (day > 30) {
            cout << "Miesiac " << month <<" ma 30 dni. Wpisz ponownie: ";
            return false;
        }
    } else if (month == 2) {
        bool leapyear (year);
        if (leapyear)
            if (day > 29) {
                cout << "Rok "<< year <<" jest przestepny. Zatem miesiac " << month << " ma maksymalnie 29 dni. Wpisz ponownie: ";
                return false;
            } else if (day > 28) {
                cout << "Miesiac " << month << " ma maksymalnie 28 dni. Wpisz ponownie: ";
                return false;
            }
    } else {
        if (day > 31) {
            cout << "Miesiac " << month << " ma maksymalnie 31 dni. Wpisz ponownie: ";
            return false;
        }
    }
}
bool AuxiliaryFunctions::leapyear (int year) {
    if(( year%4 == 0 && year%100 != 0) || ( year%400 == 0 ));
    else
        false;
}
