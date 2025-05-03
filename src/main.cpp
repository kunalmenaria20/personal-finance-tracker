#include "Transaction.h"
#include "TransactionManager.h"
int main() {
    TransactionManager manage;
    Transaction t1("2025-04-15", 12000.0, "Rent", "expense");
    Transaction t2("2025-04-15", 14000.0, "Food", "expense");
    Transaction t3("2025-04-15", 16000.0, "Rent", "income");
    Transaction t4("2025-04-15", 24000.0, "Russian", "income");
    Transaction t5("2025-04-15", 24000.0, "Rent", "income");
    Transaction t6("2025-04-15", 24000.0, "salary", "income");
    Transaction t7("2025-04-15", 24000.0, "salary", "income");
    Transaction t8("2025-04-15", 2000.0, "salary", "");
    // t1.displayTransaction();
    manage.addTransaction(t1);
    manage.addTransaction(t2);
    manage.addTransaction(t3);
    manage.addTransaction(t4);
    manage.addTransaction(t5);
    manage.addTransaction(t6);
    manage.addTransaction(t7);
    manage.addTransaction(t8);
    manage.displayAllTransactions();
    // manage.deleteTransactionByID(1);
    // manage.searchTransactionByID(5);
    // manage.displayAllTransactions();
    // manage.searchTransactionByID(2);

    // manage.saveTransactionsToCSV("transaction.csv");
    // manage.loadTransactionsFromCSV("transaction.csv");
    // manage.displayAllTransactions();
    manage.filterByCategory("Rent");
    manage.filterByCategory("Russian");
    manage.filterByType("income");
    manage.overallSummary();
    return 0;
}
