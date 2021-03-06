#include "UserManager.h"

char UserManager::chooseOptionFromMainMenu() {
    char choise;
    system("cls");
    cout << "    >>> TWOJ PROGRAM DO ZARZADANIA BUDZETEM <<<" << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choise = getLine();
    return choise;
}

bool UserManager::isUserLogedIn() {
    if (loggedInUserId > 0)
        return true;
    else
        return false;
}

char UserManager::getLine() {
    string input = "";
    char choice  = {0};

    while (true) {
        getline(cin, input);

        if (input.length() == 1) {
            choice = input[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return choice;
}

char UserManager::chooseOptionFromUserMenu() {
    char choise;
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj przychod" << endl;
    cout << "2. Dodaj wydatek" << endl;
    cout << "3. Bilans z biezacego miesiaca" << endl;
    cout << "4. Bilans z poprzedniego miesiaca" << endl;
    cout << "5. Bilans z wybranego okresu" << endl;
    cout << "---------------------------" << endl;
    cout << "6. Zmien haslo" << endl;
    cout << "7. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    choise = getLine();
    return choise;
}

void UserManager::registrationOfUser() {
    User user = enterNewUserData();
    users.push_back(user);
    fileWithUsers.addUserToFile(user);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

User UserManager::enterNewUserData() {
    User user;
    user.setUserId(getIdOfNewUser());
    string login;
    do {
        cout << "Podaj login: ";
        cin >> login;
        user.setLogin(login);
    } while (doesLoginExist(user.getLogin()) == true);
    string password, name, surname;
    cout << "Podaj haslo: ";
    cin >> password;
    user.setPassword(password);
    cout << "Podaj imie: ";
    cin >> name;
    user.setName(name);
    cout << "Podaj nazwisko: ";
    cin >> surname;
    user.setSurname(surname);
    return user;
}

int UserManager::getIdOfNewUser() {
    if (users.empty() == true)
        return 1;
    else
        return users.back().getUserId() + 1;
}

bool UserManager::doesLoginExist(string login) {
    for (int i=0; i < users.size(); i++) {
        if (users[i].getLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UserManager::showAllUsers() {
    for (int i=0; i < users.size(); i++) {
        cout << users[i].getUserId() << endl;
        cout << users[i].getLogin() << endl;
        cout << users[i].getPassword() << endl;
        cout << users[i].getName() << endl;
        cout << users[i].getSurname() << endl;
    }
}

void UserManager::loginOfUser() {
    User user;
    string login = "", password = "";
    cout << endl << "Podaj login: ";
    login = getWholeLine();
    vector <User>::iterator itr = users.begin();
    while (itr != users.end()) {
        if (itr -> getLogin() == login) {
            for (int noOfChances = 3; noOfChances > 0; noOfChances--) {
                cout << "Podaj haslo. Pozostalo prob: " << noOfChances << ": ";
                password = getWholeLine();

                if (itr -> getPassword() == password) {
                    loggedInUserId = itr -> getUserId();
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }
        itr++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}

string UserManager::getWholeLine() {
    string input = "";
    getline(cin, input);
    return input;
}

int UserManager::getIdOfLoggedInUser() {
    return loggedInUserId;
}

void UserManager::changePassword() {
    User user;
    string newPassword = "";
    cout << "Podaj nowe haslo: ";
    newPassword = getWholeLine();
    for (vector <User>::iterator itr = users.begin(); itr != users.end(); itr++) {
        if (itr -> getUserId() == loggedInUserId) {

            itr -> setPassword(newPassword);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    fileWithUsers.saveAllUsersToFile(users);
}

void UserManager::logoutOfUser() {
    loggedInUserId = 0;
}
