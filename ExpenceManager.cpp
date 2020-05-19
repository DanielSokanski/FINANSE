#include "ExpenceManager.h"

void ExpenceManager::showAllExpences() {
    system("cls");
    if (!expences.empty()) {
        cout << "             >>> Przychody <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout <<expences.size()<<endl;
        for (int i=0; i<expences.size(); i++) {
            cout << endl << "Id wydatku: " << expences[i].getExpenceId() << endl;
            cout << "Id uzytkownika:     " << expences[i].getUserId() << endl;
            cout << "Data:               " << expences[i].getDate() << endl;
            cout << "Wydatek:            " << expences[i].getItem() << endl;
            cout << "Kwota:              " << expences[i].getAmount() << endl;
        }
        cout << endl;
    } else {
        cout << endl << "Lista przychodow jest pusta." << endl << endl;
    }
    system("pause");

}
void ExpenceManager::addExpence() {
    Expences expence = enterNewExpence();
    expences.push_back(expence);
    fileWithExpences.addExpenceToFile(expence);
    cout << endl << "Wprowadzono nowy przychod." << endl << endl;
    system("pause");
}

Expences ExpenceManager::enterNewExpence() {
    Expences expence;
    expence.setExpenceId(getIdOfNewIncome());
    expence.setUserId(LOGGED_IN_USER_ID);
    string date, item;
    string amount;
    char choise;
    string correctAmount="";
    cout << "Wpisz date wydatku: ";
    cout << endl << "Czy osiagnales przychod dzisiaj? (T,N): ";
    choise = getSign();
    if ((choise=='T')||(choise=='t')) {
        expence.setDate(todaysDate());
    } else {
        cout << "Wpisz date przychodu w formacie rrrr-mm-dd:";
        cin.clear();
        getline(cin,date);
        if (checkIfDateIsCorrect(date)==false) {
            cin.clear();
            getline(cin,date);
            checkIfDateIsCorrect(date);
        }
        int dateInt = fileWithExpences.changeToNumber(date);
        expence.setDate(dateInt);
        dateInt = 0;
    }
    cout << "Czego dotyczy przychod: ";
    getline(cin, item);
    expence.setItem(item);
    cout << "Podaj kwote przychod: ";
    getline(cin, amount);
    correctAmount = changeCommaToDotInAmount(amount);
    expence.setAmount(correctAmount);
    return expence;
}
int ExpenceManager::todaysDate() {
    vector<int> date;
    time_t t = time(0);
    struct tm * now = localtime( & t );
    int todaysDateInt=0;
    date.push_back(now->tm_year + 1900);
    date.push_back(now->tm_mon+1);
    date.push_back(now->tm_mday);
    todaysDateInt = date[0]*10000+date[1]*100+date[2];

    date.clear();
    return todaysDateInt;
}
char ExpenceManager::getSign() {
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


int ExpenceManager::getIdOfNewIncome() {

    if (expences.empty() == true)
        return 1;
    else
        return expences.size()+1;
}

string ExpenceManager::changeCommaToDotInAmount(string amount) {
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

double ExpenceManager::getExpencesInCurrentMonth() {
    Expences expence;
    int date = todaysDate();
    double totalExpence = 0;
    for (int i=0; i<expences.size(); i++) {
        if (expences[i].getDate()/100 == date/100) {
            double amount= 0;
            amount = (double)atof(expences[i].getAmount().c_str());
            totalExpence = totalExpence + amount;
        }
    }
    return totalExpence;
}
double ExpenceManager::getExpencesInPreviousMonth() {
    Expences expence;
    int date = todaysDate();
    double totalExpence = 0;
    for (int i=0; i<expences.size(); i++) {
        if (expences[i].getDate()/100 == (date/100)-1) {
            double amount= 0;
            amount = (double)atof(expences[i].getAmount().c_str());
            totalExpence = totalExpence + amount;
        }
    }
    return totalExpence;
}
double ExpenceManager::getExpencesFromCustomDates(string startDate, string endDate) {
    int beginDate = fileWithExpences.changeToNumber(startDate);
    int finishDate = fileWithExpences.changeToNumber(endDate);
    double totalExpence = 0;
    for (int i=0; i<expences.size(); i++) {
        double amount = 0;
        if ((expences[i].getDate() >= beginDate)&&(expences[i].getDate() <= finishDate))

            amount = (double)atof(expences[i].getAmount().c_str());
        totalExpence = totalExpence + amount;

    }

    return totalExpence;
}

bool ExpenceManager::checkIfDateIsCorrect(string date) {

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
        if (leapyear == true)
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
bool ExpenceManager::leapyear (int year) {
    if(( year%4 == 0 && year%100 != 0) || ( year%400 == 0 ));
    else
        false;
}

void ExpenceManager::showExpencesData(Expences expence) {
    cout << endl << "Id:         " << expence.getExpenceId() << endl;
    cout << "Id uzytkownika:     " << expence.getUserId() << endl;
    cout << "Data:               " << expence.getDate() << endl;
    cout << "Przychod:           " << expence.getItem() << endl;
    cout << "Kwota:              " << expence.getAmount() << endl;
}
