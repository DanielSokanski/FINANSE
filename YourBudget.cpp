#include "YourBudget.h"


bool YourBudget::isUserLogedIn() {
    userManager.isUserLogedIn();
}

char YourBudget::chooseOptionFromMainMenu() {
    userManager.chooseOptionFromMainMenu();
}

char YourBudget::chooseOptionFromUserMenu() {
    userManager.chooseOptionFromUserMenu();
}

void YourBudget::registrationOfUser() {
    userManager.registrationOfUser();
}

void YourBudget::showAllUsers() {
    userManager.showAllUsers();
}

void YourBudget::loginOfUser() {
    userManager.loginOfUser();
    if (isUserLogedIn()) {
        incomeManager = new IncomeManager (userManager.getIdOfLoggedInUser());
        expenceManager = new ExpenceManager (userManager.getIdOfLoggedInUser());
    }
}

void YourBudget::compareExpencesToIncomesInCurrentMonth() {
    double totalIncomesInCurrentMonth = incomeManager -> getIncomesInCurrentMonth();
    double totalExpencesInCurrentMonth = expenceManager -> getExpencesInCurrentMonth();
    double balanceInCurrentMonth = 0;
    cout << "Przychody z biezacego miesaca = " << totalIncomesInCurrentMonth << endl;
    cout << "Koszty z biezacego miesaca = " << totalExpencesInCurrentMonth << endl;
    if (totalIncomesInCurrentMonth>totalExpencesInCurrentMonth) {
        balanceInCurrentMonth = totalIncomesInCurrentMonth - totalExpencesInCurrentMonth;
        cout << "W biezacym miesiacu wykazano zysk w wysokosci: " << balanceInCurrentMonth << " zl" << endl;
    } else if (totalExpencesInCurrentMonth>totalIncomesInCurrentMonth) {
        balanceInCurrentMonth = totalExpencesInCurrentMonth - totalIncomesInCurrentMonth;
        cout << "W biezacym miesiacu wykazano strate w wysokosci: " << balanceInCurrentMonth << " zl" << endl;
    } else if (totalExpencesInCurrentMonth==totalIncomesInCurrentMonth) {
        cout << "W biezacym miesiacu bilans przychodow i kosztow wyniosl : " << balanceInCurrentMonth << " zl" << endl;
    }
    system ("pause");
}

void YourBudget::addIncome() {
    incomeManager -> addIncomes();
}

void YourBudget::addExpence() {
    expenceManager -> addExpence();
}

void YourBudget::compareExpencesToIncomesInPreviousMonth() {
    double totalIncomesInPreviousMonth = incomeManager -> getIncomesInPreviousMonth();
    double totalExpencesInPreviousMonth = expenceManager -> getExpencesInPreviousMonth();
    double balanceInPreviousMonth = 0;
    cout << "Przychody z biezacego miesaca = " << totalIncomesInPreviousMonth << endl;
    cout << "Koszty z biezacego miesaca = " << totalExpencesInPreviousMonth << endl;
    if (totalIncomesInPreviousMonth>totalExpencesInPreviousMonth) {
        balanceInPreviousMonth = totalIncomesInPreviousMonth - totalExpencesInPreviousMonth;
        cout << "W biezacym miesiacu wykazano zysk w wysokosci: " << balanceInPreviousMonth << " zl" << endl;
    } else if (totalExpencesInPreviousMonth>totalIncomesInPreviousMonth) {
        balanceInPreviousMonth = totalExpencesInPreviousMonth - totalIncomesInPreviousMonth;
        cout << "W biezacym miesiacu wykazano strate w wysokosci: " << balanceInPreviousMonth << " zl" << endl;
    } else if (totalExpencesInPreviousMonth==totalIncomesInPreviousMonth) {
        cout << "W biezacym miesiacu bilans przychodow i kosztow wyniosl : " << balanceInPreviousMonth << " zl" << endl;
    }
    system ("pause");
}


void YourBudget::compareExpencesToIncomesFromCustomDates() {
    string startDate = "";
    string endDate = "";
    Incomes income;
    cout << "Podaj poczatkowa date (rrrr-mm-dd):";
    getline(cin, startDate);
    cout << "Podaj koncowa date(rrrr-mm-dd):";
    getline(cin, endDate);
    double totalIncomesInCustomDates = incomeManager -> getIncomesFromCustomDates(startDate,endDate);
    double totalExpencesInCustomDates = expenceManager -> getExpencesFromCustomDates(startDate,endDate);
    double balanceInCustomDates = 0;
    cout << "Przychody z biezacego okresu = " << totalIncomesInCustomDates << endl;
    cout << "Koszty z biezacego okresu = " << totalExpencesInCustomDates << endl;
    if (totalIncomesInCustomDates > totalExpencesInCustomDates) {
        balanceInCustomDates = totalIncomesInCustomDates - totalExpencesInCustomDates;
        cout << "W wybranym okresie wykazano zysk w wysokosci: " << balanceInCustomDates << " zl" << endl;
    } else if (totalExpencesInCustomDates>totalIncomesInCustomDates) {
        balanceInCustomDates = totalExpencesInCustomDates - totalIncomesInCustomDates;
        cout << "W wybranym okresie wykazano strate w wysokosci: " << balanceInCustomDates << " zl" << endl;
    } else if (totalExpencesInCustomDates==totalIncomesInCustomDates) {
        cout << "W wybranym okresie bilans przychodow i kosztow wyniosl : " << balanceInCustomDates << " zl" << endl;
    }
    system ("pause");
}

void YourBudget::changePassword() {
    userManager.changePassword();
}
void YourBudget::logoutOfUser() {
    userManager.logoutOfUser();
}
void YourBudget::showAllIncomes() {
    incomeManager -> showAllIncomes();
}
