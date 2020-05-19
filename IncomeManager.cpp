#include "IncomeManager.h"

void IncomeManager::showAllIncomes() {
    system("cls");
    if (!incomes.empty()) {
        cout << "             >>> Wydatki <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        cout <<incomes.size()<<endl;
        for (int i=0; i<incomes.size(); i++) {
            cout << endl << "Id wydatku: " << incomes[i].getIncomeId() << endl;
            cout << "Id uzytkownika:     " << incomes[i].getUserId() << endl;
            cout << "Data:               " << incomes[i].getDate() << endl;
            cout << "Wydatek:            " << incomes[i].getItem() << endl;
            cout << "Kwota:              " << incomes[i].getAmount() << endl;
        }
        cout << endl;
    } else {
        cout << endl << "Lista wydatkow jest pusta." << endl << endl;
    }
    system("pause");

}
void IncomeManager::addIncomes() {
    Incomes income = enterNewIncome();
    incomes.push_back(income);
    fileWithIncomes.addIncomesToFile(income);
    cout << endl << "Wprowadzono nowy wydatek." << endl << endl;
    system("pause");
}

Incomes IncomeManager::enterNewIncome() {
    Incomes income;
    income.setIncomeId(getIdOfNewIncome());
    income.setUserId(LOGGED_IN_USER_ID);
    string date, item;
    string amount;
    char choise;
    string correctAmount="";
    cout << "Wpisz date wydatku: ";
    cout << endl << "Czy dzis poniosles wydatek? (T,N): ";
    choise = getSign();
    if ((choise=='T')||(choise=='t')) {
        income.setDate(todaysDate());
    } else {
        cout << "Wpisz date w formacie rrrr-mm-dd:";
        cin.clear();
        getline(cin,date);
        if (checkIfDateIsCorrect(date)==false) {
            cin.clear();
            getline(cin,date);
            checkIfDateIsCorrect(date);
        }
        int dateInt = fileWithIncomes.changeToNumber(date);
        income.setDate(dateInt);
        dateInt = 0;
    }
    cout << "Czego dotyczy wydatek: ";
    getline(cin, item);
    income.setItem(item);
    cout << "Podaj kwote wydatku: ";
    getline(cin, amount);
    correctAmount = changeCommaToDotInAmount(amount);
    income.setAmount(correctAmount);


    return income;
}
int IncomeManager::todaysDate() {
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
char IncomeManager::getSign() {
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

int IncomeManager::getIdOfNewIncome() {

    if (incomes.empty() == true)
        return 1;
    else
        return incomes.size()+1;
}

string IncomeManager::changeCommaToDotInAmount(string amount) {
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

double IncomeManager::getIncomesInCurrentMonth() {
    Incomes income;
    int date = todaysDate();
    double totalIncomes = 0;
    for (int i=0; i<incomes.size(); i++) {
        if (incomes[i].getDate()/100 == date/100) {
            double amount= 0;
            amount = (double)atof(incomes[i].getAmount().c_str());
            totalIncomes = totalIncomes + amount;
        }
    }
    return totalIncomes;
}
double IncomeManager::getIncomesInPreviousMonth() {
    Incomes income;
    int date = todaysDate();
    double totalIncomes = 0;
    for (int i=0; i<incomes.size(); i++) {
        if (incomes[i].getDate()/100 == (date/100)-1) {
            double amount= 0;
            amount = (double)atof(incomes[i].getAmount().c_str());
            totalIncomes = totalIncomes + amount;
        }
    }
    return totalIncomes;
}
double IncomeManager::getIncomesFromCustomDates(string startDate, string endDate) {
    int beginDate = fileWithIncomes.changeToNumber(startDate);
    int finishDate = fileWithIncomes.changeToNumber(endDate);
    double totalIncomes = 0;
    for (int i=0; i<incomes.size(); i++) {
        double amount = 0;
        if ((incomes[i].getDate() >= beginDate)&&(incomes[i].getDate() <= finishDate))

            amount = (double)atof(incomes[i].getAmount().c_str());
        totalIncomes = totalIncomes + amount;

    }

    return totalIncomes;
}

bool IncomeManager::checkIfDateIsCorrect(string date) {

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
bool IncomeManager::leapyear (int year) {
    if(( year%4 == 0 && year%100 != 0) || ( year%400 == 0 ));
    else
        false;
}

void IncomeManager::showIncomesData(Incomes income) {
    cout << endl << "Id:         " << income.getIncomeId() << endl;
    cout << "Id uzytkownika:     " << income.getUserId() << endl;
    cout << "Data:               " << income.getDate() << endl;
    cout << "Przychod:           " << income.getItem() << endl;
    cout << "Kwota:              " << income.getAmount() << endl;
}
