#include "FileWithExpences.h"

vector <Expences> FileWithExpences::loadExpencesOfLoggedInUser(int userId) {
    Expences expence;
    vector <Expences> expences;
    int USERID = 0;
    string amount="";
    CMarkup xml;
    bool fileExists = xml.Load( "expences.xml" );
    xml.FindElem( "Expences" );
    xml.IntoElem();
    while(xml.FindElem( "Expence" )) {
        xml.IntoElem();
        xml.FindElem("userId");
        USERID = atoi(MCD_2PCSZ(xml.GetData()));

        if (USERID == userId) {
            xml.FindElem("expenceId");
            expence.setExpenceId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("userId");
            expence.setUserId(atoi(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("date");
            expence.setDate(changeToNumber(MCD_2PCSZ(xml.GetData())));
            xml.FindElem("item");
            expence.setItem(MCD_2PCSZ(xml.GetData()));
            xml.FindElem("amount");
            amount = MCD_2PCSZ(xml.GetData());
            expence.setAmount(MCD_2PCSZ(xml.GetData()));
            expences.push_back(expence);

        }
        xml.OutOfElem();
    }
    return expences;
}

void FileWithExpences::addExpenceToFile(Expences expences) {
    CMarkup xml;
    bool fileExists = xml.Load("expences.xml");

    if (!fileExists) {
        xml.SetDoc("<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n");
        xml.AddElem("Expences");
    }

    xml.FindElem();
    xml.IntoElem();
    xml.AddElem("Expence");
    xml.IntoElem();
    xml.AddElem("expenceId", expences.getExpenceId());
    xml.AddElem("userId", expences.getUserId());
    xml.AddElem("date", expences.getDate());
    xml.AddElem("item", expences.getItem());
    xml.AddElem("amount", expences.getAmount());
    xml.Save("expences.xml");
    xml.OutOfElem();
}

int FileWithExpences::changeToNumber(string date) {
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
int FileWithExpences::loadUserId() {
    CMarkup xml;

    xml.Load( "expences.xml" );
    xml.FindElem( "Expences" );
    xml.IntoElem();
    xml.FindElem( "Expence" );
    xml.IntoElem();
    xml.FindElem("userId");
    int USERID = atoi(MCD_2PCSZ(xml.GetData()));
    xml.OutOfElem();
    return USERID;
}

