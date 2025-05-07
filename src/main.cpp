#include "Transaction.h"
#include "TransactionManager.h"
#include "Utils.h"
#include <iostream>
#include <string>
using namespace std;

void showMenu()
{
    cout << "\n=== Personal Finance Tracker ===\n";
    cout << "1. Add Transaction\n";
    cout << "2. View All Transactions\n";
    cout << "3. Delete Transaction by ID\n";
    cout << "4. Search Transaction by ID\n";
    cout << "5. Filter by Category\n";
    cout << "6. Filter by Type\n";
    cout << "7. Show Summary\n";
    cout << "8. Save Transactions to CSV\n";
    cout << "9. Load Transactions from CSV\n";
    cout << "0. Exit\n";
    cout << "Enter your choice: ";
}

Transaction createTransactionFromInput()
{
    string date, category, type;
    double amount;

    // cin.ignore(); // Clear input buffer
    cout << "Enter date (YYYY-MM-DD): ";
    getline(cin, date);

    cout << "Enter amount: ";
    cin >> amount;
    
    cin.ignore(); // Clear newline

    cout << "Enter category: ";
    getline(cin, category);

    cout << "Enter type: ";
    getline(cin, type);

    return Transaction(date, amount, category, type);
}

int main()
{
    TransactionManager manager;
    int choice;
    string filename = "transactions.csv";

    do
    {
        showMenu();
        cin >> choice;
        cin.ignore(); // flush newline

        switch (choice)
        {
        case 1:
        {
            Transaction t = createTransactionFromInput();
            manager.addTransaction(t);
            break;
        }
        case 2:
            manager.displayAllTransactions();
            break;
        case 3:
        {
            int id;
            cout << "Enter ID to delete: ";
            cin >> id;
            manager.deleteTransactionByID(id);
            break;
        }
        case 4:
        {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            manager.searchTransactionByID(id);
            break;
        }
        case 5:
        {
            string cat;
            cout << "Enter category: ";
            // cin.ignore();
            getline(cin, cat);
            manager.filterByCategory(cat);
            break;
        }
        case 6:
        {
            string type;
            cout << "Enter type (income/expense): ";
            // cin.ignore();
            getline(cin, type);
            manager.filterByType(type);
            break;
        }
        case 7:
            manager.overallSummary();
            break;
        case 8:
            manager.saveTransactionsToCSV(filename);
            break;
        case 9:
            manager.loadTransactionsFromCSV(filename);
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
