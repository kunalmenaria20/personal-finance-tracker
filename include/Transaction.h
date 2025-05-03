#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include <fstream>
using namespace std;
class Transaction {
private:
    int id;
    string date;
    double amount;
    string category;
    string type;

public:
    Transaction(const string& tDate, double tAmt, const string& tCatg, const string& tType);
    void displayTransaction() const;
    int getId()const;
    void setId(int newId);
    string toCSV() const;
    Transaction static fromCSV(const string& line);
    string getCategory() const;
    string getType()const;
    double getAmount() const;

};
#endif
