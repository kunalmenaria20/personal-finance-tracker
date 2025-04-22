#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>

class Transaction {
private:
    int id;
    std::string date;
    double amount;
    std::string category;
    std::string type;

public:
    Transaction(int tId, const std::string& tDate, double tAmt, const std::string& tCatg, const std::string& tType);
    void displayTransaction() const;
    int getId();
};
#endif
