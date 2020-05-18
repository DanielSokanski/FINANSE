#include "YourBudget.h"


bool YourBudget::isUserLogedIn()
{
    userManager.isUserLogedIn();
}

char YourBudget::chooseOptionFromMainMenu()
{
    userManager.chooseOptionFromMainMenu();
}

char YourBudget::chooseOptionFromUserMenu()
{
    userManager.chooseOptionFromUserMenu();
}

void YourBudget::registrationOfUser()
{
    userManager.registrationOfUser();
}

void YourBudget::showAllUsers()
{
    userManager.showAllUsers();
}

void YourBudget::loginOfUser()
{
    userManager.loginOfUser();
    if (isUserLogedIn())
    {
        incomeManager = new IncomeManager (userManager.getIdOfLoggedInUser());
       // expenceManager = new ExpenceManager (FILE_NAME_WITH_EXPENCES, userManager.getIdOfLoggedInUser());
    }
}
/*
void YourBudget::compareExpencesToIncomesInCurrentMonth()
{
    userManager.compareExpencesToIncomesInCurrentMonth();
}
*/
void YourBudget::addIncome()
{
    incomeManager -> addIncomes();
}
/*
void YourBudget::addExpence()
{
    expenceManager -> addExpence();
}
void YourBudget::compareExpencesToIncomesInPreviousMonth()
{
    userManager.compareExpencesToIncomesInPreviousMonth();
}
void YourBudget::compareExpencesToIncomesFromCustomDates()
{
    userManager.compareExpencesToIncomesFromCustomDates();
}*/
void YourBudget::changePassword()
{
    userManager.changePassword();
}
void YourBudget::logoutOfUser()
{
    userManager.logoutOfUser();
}
void YourBudget::showAllIncomes()
{
    incomeManager -> showAllIncomes();
}

