#ifndef TRANSACTION_MANAGER_H
#define TRANSACTION_MANAGER_H
#include "Transaction.h"
#include <vector>
using namespace std;
class TransactionManager {
    private:
    vector<Transaction> transactions;
    int nextTransactionId=1;
    public:
    
    void addTransaction(Transaction& t);
    void displayAllTransactions() const;
    void deleteTransactionByID(int to_deleteId);
    void searchTransactionByID(int id);
    void saveTransactionsToCSV(const string& filename) const ;
    void loadTransactionsFromCSV(const string& filename);
    void filterByCategory(const string& category) const;
    void filterByType(const string& type) const;
    void overallSummary() const;

};

#endif