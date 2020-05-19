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
    choise = AuxiliaryFunctions::getSign();
    if ((choise=='T')||(choise=='t')) {
        income.setDate(AuxiliaryFunctions::todaysDate());
    } else {
        cout << "Wpisz date w formacie rrrr-mm-dd:";
        cin.clear();
        getline(cin,date);
        if (AuxiliaryFunctions::checkIfDateIsCorrect(date)==false) {
            cin.clear();
            getline(cin,date);
            AuxiliaryFunctions::checkIfDateIsCorrect(date);
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
    correctAmount = AuxiliaryFunctions::changeCommaToDotInAmount(amount);
    income.setAmount(correctAmount);


    return income;
}

int IncomeManager::getIdOfNewIncome() {

    if (incomes.empty() == true)
        return 1;
    else
        return incomes.size()+1;
}

double IncomeManager::getIncomesInCurrentMonth() {
    Incomes income;
    int date = AuxiliaryFunctions::todaysDate();
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
    int date = AuxiliaryFunctions::todaysDate();
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

void IncomeManager::showIncomesData(Incomes income) {
    cout << endl << "Id:         " << income.getIncomeId() << endl;
    cout << "Id uzytkownika:     " << income.getUserId() << endl;
    cout << "Data:               " << income.getDate() << endl;
    cout << "Przychod:           " << income.getItem() << endl;
    cout << "Kwota:              " << income.getAmount() << endl;
}
