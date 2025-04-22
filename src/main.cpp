#include "Transaction.h"
#include "TransactionManager.h"
int main() {
    TransactionManager manage;
    Transaction t1(1, "2025-04-15", 12000.0, "Rent", "Expense");
    Transaction t2(2, "2025-04-15", 14000.0, "Rent", "Expense");
    Transaction t3(3, "2025-04-15", 16000.0, "Rent", "Expense");
    Transaction t4(1, "2025-04-15", 24000.0, "Rent", "Expense");
    // t1.displayTransaction();
    manage.addTransaction(t1);
    manage.addTransaction(t2);
    manage.addTransaction(t3);
    manage.displayAllTransactions();
    manage.deleteTransactionByID(4);
    manage.displayAllTransactions();
    manage.searchTransactionByID(1);
    return 0;
}
