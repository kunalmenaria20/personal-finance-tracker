#include "Transaction.h"
#include "TransactionManager.h"
int main() {
    TransactionManager manage;
    Transaction t1("2025-04-15", 12000.0, "Rent", "Expense");
    Transaction t2("2025-04-15", 14000.0, "Rent", "Expense");
    Transaction t3("2025-04-15", 16000.0, "Rent", "Expense");
    Transaction t4("2025-04-15", 24000.0, "Rent", "Expense");
    // t1.displayTransaction();
    manage.addTransaction(t1);
    manage.addTransaction(t2);
    manage.addTransaction(t3);
    manage.addTransaction(t4);
    manage.displayAllTransactions();
    manage.deleteTransactionByID(1);
    manage.searchTransactionByID(5);
    manage.displayAllTransactions();
    manage.searchTransactionByID(2);
    return 0;
}
