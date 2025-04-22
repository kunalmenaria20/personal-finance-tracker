#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H
#include "Transaction.h"
#include <vector>
using namespace std;
class TransactionManager {
    private:
    vector<Transaction> transactions;
    public:
    
    void addTransaction(const Transaction& t);
    void displayAllTransactions() const;
    void deleteTransactionByID(int to_deleteId);
    void searchTransactionByID(int id);
};

#endif