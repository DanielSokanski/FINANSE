#include "Expences.h"

void Expences::setExpenceId(int newExpenceId) {
    if (newExpenceId >=0)
        expenceId=newExpenceId;
}
void Expences::setUserId(int newUserId) {
    userId=newUserId;
}
void Expences::setDate(string newDate) {
    date=newDate;
}
void Expences::setItem(string newItem) {
    item=newItem;
}
void Expences::setAmount(string newAmount) {
    amount=newAmount;
}
int Expences::getExpenceId() {
    return expenceId;
}
int Expences::getUserId() {
    return userId;
}
string Expences::getDate() {
    return date;
}
string Expences::getItem() {
    return item;
}
string Expences::getAmount() {
    return amount;
}
