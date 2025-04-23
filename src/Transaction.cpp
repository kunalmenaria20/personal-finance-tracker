#include "Transaction.h"
#include <iostream>
using namespace std;

Transaction::Transaction(const string& tDate, double tAmt, const string& tCatg, const string& tType)
    :date(tDate), amount(tAmt), category(tCatg), type(tType) {}                                         //constructor

void Transaction::displayTransaction() const {
    cout << "Id: " << id << " || "<< "Date: " << date << " || "<< "Amount: " << amount << " || "
        << "Category: " << category << " || "<< "Type: " << type << endl;
}
int Transaction::getId() const{
    return id;
}
void Transaction::setId(int newId){
    id=newId;
}