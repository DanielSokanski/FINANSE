#include "IncomeManager.h"


void IncomeManager::showAllIncomes() {
    system("cls");
    if (!incomes.empty()) {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
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
    //fileWithUsers.addIncomeToFile(income);
    cout << endl << "Wprowadzono nowy przychod." << endl << endl;
    system("pause");
}

Incomes IncomeManager::enterNewIncome() {
    Incomes income;
    income.setIncomeId(getIdOfNewIncome());
    income.setUserId(LOGGED_IN_USER_ID);
    string date, item;
    string amount;
    char choise;
    cout << "Wpisz date wydatku: ";
    cout << endl << "Czy dzis poniosles wydatek? (T,N): ";
    choise = getSign();
    if ((choise=='T')||(choise=='t')) {
        int correctDate=todaysDate();
        income.setDate(correctDate);
    } else {
    cout << "Wpisz date w formacie rrr-mm-dd:";
    getline(cin ,date);
    if (checkIfDateIsCorrect(date)==false){
        cin.clear();
        getline(cin ,date);
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
    cin >> amount;
    float correctAmount = changeCommaToDotInAmount(amount);
    income.setAmount(correctAmount);
    correctAmount = 0;
    incomes.push_back(income);
    return incomes;
}
int IncomeManager::todaysDate() {
    vector<int> date;
    date.clear();
    int currentDate[7];
    time_t t = time(0);
    struct tm * now = localtime( & t );

    if(((now->tm_mon+1)<10)&&((now->tm_mday)<10)) {
        date.push_back(now->tm_year + 1900);
        date.push_back(0);
        date.push_back(now->tm_mon+1);
        date.push_back(0);
        date.push_back(now->tm_mday);
    } else if ((now->tm_mday)<10) {
        date.push_back(now->tm_year + 1900);
        date.push_back(now->tm_mon+1);
        date.push_back(0);
        date.push_back(now->tm_mday);
    } else if((now->tm_mon+1)<10) {
        date.push_back(now->tm_year + 1900);
        date.push_back(0);
        date.push_back(now->tm_mon+1);
        date.push_back(now->tm_mday);
    } else {
        date.push_back(now->tm_year + 1900);
        date.push_back(now->tm_mon+1);
        date.push_back(now->tm_mday);
    }
    for (int i=0; i<date.size(); i++)
    {
        currentDate[i] = date[i];
    }
    return currentDate;
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
        return incomes.back().getIncomeId() + 1;
}

float IncomeManager::changeCommaToDotInAmount(string amount) {
    float correctAmount;
    for (int i=0; i<amount.length(); i++) {
        if (amount[i]==",")
            amount[i]==".";
    }
    correctAmount=atof(amount.C_str());
    return correctAmount;
}/*
float IncomeManager::getIncomesFromCurrentMonth() {
    int date = todaysDate();
    float totalIncomes = 0;
    for (int i=0; i<6; i++) {
        if (incomes[i].getDate()==date[i]) {
            totalIncomes = totalIncomes + incomes.getAmount[i];
        }
    }
    return totalIncomes;
}
void IncomeManager::getIncomesFromPreviousMonth() {
    int date = todaysDate();
    for (int i=0; i<date.length(); i++) {
        if((date[4]==1)&&(date[5]==0]) {
            date[4]=0;
            date[5]=9;
        } else {
            date[5]=date[5]-1;
        }
    }
    float totalIncomes = 0;
    for (int i=0; i<6; i++) {
        if (incomes[i].getDate()==date[i]) {
            totalIncomes = totalIncomes + incomes.getAmount[i];
        }
    }
    return totalIncomes;
}
void IncomeManager::getIncomesFromCustomDate() {
    string startingDate, endDate;
    float totalIncomes = 0;
    cout << "Wpisz date poczatkowa (w formacie rrrr-mm-dd: ";
    getline (cin, startingDate);
    int beginDate = FileWithIncomes.changeToNumber(startingDate);
    cout << "Wpisz date koncowa (w formacie rrrr-mm-dd: ";
    getline (cin, endDate);
    int finishDate = FileWithIncomes.changeToNumber(startingDate);

    for (int i = 0; i<incomes.size(); i++) {
        if ((incomes[i].getDate() > beginDate)&&(incomes[i].getDate() > endDate)) {
            totalIncomes = totalIncomes + incomes.getAmount[i];
        }
    }
    return totalIncomes;
}*/
bool IncomeManager::checkIfDateIsCorrect(string date) {
    int day, month, year;
    string seperating = "";
    vector<string> tempDate;
    for (int i=0; i<date.length(); i++) {
        if(date[i]!="-"){
            seperating = seperating + date[i];
        }
        else{
            tempDate.push_back(seperating);
            seperating = "";
        }
    }
    tempDate.push_back(seperating);
    int year = atoi(tempDate[0]);
    if ((year < 2000) || (year > 2021)) {
        cout<< "Nieprawidlowy rok. Wpisz ponownie: ";
    }
    int month = atoi(tempDate[1]);
    if (month > 12) {
        cout << "Nieprawidlowy miesiac. Wpisz ponownie: ";
    }
    int day = atoi(tempDate[2]);
    if ((month == 4) || (month == 6) || (month == 9) || (month == 11)) {
        if (day > 30) {
            cout << "Miesiac " << month <<" ma 30 dni. Wpisz ponownie: ";
        }
    } else if (month == 2) {
        bool leapyear (year);
        if (leapyear == true)
            if (day > 29) {
                cout << "Rok "<< year <<" jest przestepny. Zatem miesiac " << month << " ma maksymalnie 29 dni. Wpisz ponownie: ";
            } else if (day > 28) {
                cout << "Miesiac " << month << " ma maksymalnie 28 dni. Wpisz ponownie: ";
            }
    } else {
        if (day > 31) {
            cout << "Miesiac " << month << " ma maksymalnie 31 dni. Wpisz ponownie: ";
        }
    }
}
bool IncomeManager::leapyear (int year) {
    if(( year%4 == 0 && year%100 != 0) || ( year%400 == 0 ));
    else
        false;
}

void IncomeManager::showIncomesData(Incomes income)
{
    cout << endl << "Id:         " << income.getIncomeId() << endl;
    cout << "Id uzytkownika:     " << income.getUserId() << endl;
    cout << "Data:               " << income.getDate() << endl;
    cout << "Przychod:           " << income.getItem() << endl;
    cout << "Kwota:              " << income.getAmount() << endl;
}
