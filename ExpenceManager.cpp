#include "ExpenceManager.h"

void ExpenceManager::showAllExpences() {
    system("cls");
    if (!expences.empty()) {
        cout << "             >>> Wydatki <<<" << endl;
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
        cout << endl << "Lista wydatkow jest pusta." << endl << endl;
    }
    system("pause");

}
void ExpenceManager::addExpence() {
    Expences expence = enterNewExpence();
    expences.push_back(expence);
    fileWithExpences.addExpenceToFile(expence);
    cout << endl << "Wprowadzono nowy wydatek." << endl << endl;
    system("pause");
}

Expences ExpenceManager::enterNewExpence() {
    Expences expence;
    expence.setExpenceId(fileWithExpences.getIdOfNewExpence());
    expence.setUserId(LOGGED_IN_USER_ID);
    string date, item;
    string amount;
    char choise;
    string correctAmount="";
    cout << "Wpisz date wydatku: ";
    cout << endl << "Czy dzisiaj mia³ miejsce wydatek? (T,N): ";
    choise = AuxiliaryFunctions::getSign();
    if ((choise=='T')||(choise=='t')) {
        expence.setDate(AuxiliaryFunctions::todaysDate());
    } else {
        cout << "Wpisz date wydatku w formacie rrrr-mm-dd:";
        cin.clear();
        getline(cin,date);
        if (AuxiliaryFunctions::checkIfDateIsCorrect(date)==false) {
            cin.clear();
            getline(cin,date);
            AuxiliaryFunctions::checkIfDateIsCorrect(date);
        }
        expence.setDate(date);
    }
    cout << "Czego dotyczy wydatek: ";
    getline(cin, item);
    expence.setItem(item);
    cout << "Podaj kwote wydatku: ";
    getline(cin, amount);
    correctAmount = AuxiliaryFunctions::changeCommaToDotInAmount(amount);
    expence.setAmount(correctAmount);
    return expence;
}

double ExpenceManager::getExpencesInCurrentMonth() {
    Expences expence;
    string dateInString = AuxiliaryFunctions::todaysDate();
    int date = AuxiliaryFunctions::todaysDateInt(dateInString);
    double totalExpence = 0;
    for (int i=0; i<expences.size(); i++) {
        if (AuxiliaryFunctions::todaysDateInt(expences[i].getDate())/100 == date/100) {
            double amount= 0;
            amount = (double)atof(expences[i].getAmount().c_str());
            totalExpence = totalExpence + amount;
        }
    }
    return totalExpence;
}
double ExpenceManager::getExpencesInPreviousMonth() {
    Expences expence;
    string dateInString = AuxiliaryFunctions::todaysDate();
    int date = AuxiliaryFunctions::todaysDateInt(dateInString);
    double totalExpence = 0;
    for (int i=0; i<expences.size(); i++) {
        if (AuxiliaryFunctions::todaysDateInt(expences[i].getDate())/100 == (date/100)-1) {
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
        if ((AuxiliaryFunctions::todaysDateInt(expences[i].getDate()) >= beginDate)&&(AuxiliaryFunctions::todaysDateInt(expences[i].getDate()) <= finishDate))

            amount = (double)atof(expences[i].getAmount().c_str());
        totalExpence = totalExpence + amount;

    }

    return totalExpence;
}

void ExpenceManager::showExpencesData(Expences expence) {
    cout << endl << "Id:         " << expence.getExpenceId() << endl;
    cout << "Id uzytkownika:     " << expence.getUserId() << endl;
    cout << "Data:               " << expence.getDate() << endl;
    cout << "Wydatek:           " << expence.getItem() << endl;
    cout << "Kwota:              " << expence.getAmount() << endl;
}
