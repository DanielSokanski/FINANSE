#include "Incomes.h"

void Incomes::setIncomeId(int newIncomeId)
{
    if (newIncomeId >=0)
        incomeId=newIncomeId;
}
void Incomes::setUserId(int newUserId)
{
    userId=newUserId;
}
void Incomes::setDate(int newDate)
{
    date=newDate;
}
void Incomes::setItem(string newItem)
{
    item=newItem;
}
void Incomes::setAmount(double newAmount)
{
    amount=newAmount;
}
int Incomes::getIncomeId()
{
    return incomeId;
}
int Incomes::getUserId()
{
    return userId;
}
int Incomes::getDate()
{
    return date;
}
string Incomes::getItem()
{
    return item;
}
double Incomes::getAmount()
{
    return amount;
}
