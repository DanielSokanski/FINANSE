#include "FileWithIncomes.h"

vector <Incomes> FileWithIncomes::loadIncomesOfLoggedInUser(int userId) {
    Incomes income;
    vector <Incomes> incomes;

    int USERID = 0;
    string amount="";
    CMarkup xml;
    bool fileExists = xml.Load( "incomes.xml" );
    xml.FindElem( "Incomes" );
    xml.IntoElem();
    while(xml.FindElem( "Income" )) {
        xml.IntoElem();
        xml.FindElem("userId");
        USERID = atoi(MCD_2PCSZ(xml.GetData()));
        if (USERID == userId) {
            xml.FindElem("incomeId");
            income.setIncomeId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("userId");
            income.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("date");
            income.setDate(changeToNumber(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("item");
            income.setItem(MCD_2PCSZ(xml.GetData()));
            xml.FindElem("amount");
            amount = MCD_2PCSZ(xml.GetData());
            income.setAmount(MCD_2PCSZ(xml.GetData()));
            incomes.push_back(income);
        }
        xml.OutOfElem();
    }
    return incomes;
}

void FileWithIncomes::addIncomesToFile(Incomes incomes) {
    CMarkup xml;
    bool fileExists = xml.Load("incomes.xml");

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Incomes");
    }
    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Income");
    xml.IntoElem();
    xml.AddElem("incomeId", incomes.getIncomeId());
    xml.AddElem("userId", incomes.getUserId());
    xml.AddElem("date", incomes.getDate());
    xml.AddElem("item", incomes.getItem());
    xml.AddElem("amount", incomes.getAmount());
    xml.Save("incomes.xml");
    xml.OutOfElem();
}

int FileWithIncomes::changeToNumber(string date) {
    int fullDate = 0;
    vector<string> tempDate;
    tempDate.clear();
    string yearmonthday = "";
    for (int i=0; i<date.length(); i++) {
        if(date[i]!='-') {
            yearmonthday = yearmonthday + date[i];
        }
    }
    tempDate.push_back(yearmonthday);
    fullDate = atoi(tempDate[0].c_str());

    return fullDate;
}
int FileWithIncomes::loadUserId() {
    CMarkup xml;

    xml.Load( "incomes.xml" );
    xml.FindElem( "Incomes" );
    xml.IntoElem();
    xml.FindElem( "Income" );
    xml.IntoElem();
    xml.FindElem("userId");
    int USERID = atoi(MCD_2PCSZ(xml.GetData()));
    xml.OutOfElem();
    return USERID;
}

