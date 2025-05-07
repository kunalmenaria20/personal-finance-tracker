#include <iostream>
#include "Utils.h"

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
    std::string date, category, type;
    double amount;

    std::cout << "Enter date (YYYY-MM-DD): ";
    std::getline(std::cin >> std::ws, date);

    std::cout << "Enter amount: ";
    while (!(std::cin >> amount) || amount < 0)
    {
        std::cout << "Invalid amount. Try again: ";
        std::cin.clear();
        std::cin.ignore(1000, '\n');
    }

    std::cin.ignore(); // Clear newline after number input

    std::cout << "Enter category: ";
    std::getline(std::cin, category);

    std::cout << "Enter type (income/expense): ";
    while (true)
    {
        std::getline(std::cin, type);
        if (type == "income" || type == "expense")
            break;
        std::cout << "Invalid type. Enter 'income' or 'expense': ";
    }

    return Transaction(date, amount, category, type);
}


