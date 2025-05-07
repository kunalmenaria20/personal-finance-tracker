#include "TransactionManager.h"


void TransactionManager::addTransaction(Transaction &t)
{

    
    // check for empty inputs
    if (t.getCategory() == "" || t.getType() == "")
    {
        cout << "Choose category and type" << endl;
    }
    else
    {
        
        transactions.push_back(t);
        
        cout << "Transaction added successfully.\n";
    }
    t.setId(nextTransactionId++);
}
void TransactionManager::deleteTransactionByID(int to_deleteId)
{
    bool found = false;
    for (auto it = transactions.begin(); it != transactions.end(); ++it)
    {
        if (it->getId() == to_deleteId)
        {
            transactions.erase(it);
            found = true;
            cout << "Transaction successfully deleted.\n";
            break;
        }
    }
    if (found == false)
    {
        cout << "no transaction found with ID: " << to_deleteId << "\n";
    }
}
void TransactionManager::displayAllTransactions() const
{
    if (transactions.empty() == true)
    {
        cout << "No Transactions Found\n";
        return;
    }
    for (const Transaction &t : transactions)
    { // iteration in the transcation to get to the every element//
        t.displayTransaction();
        cout << endl;
    }
}
void TransactionManager::searchTransactionByID(int id)
{
    bool found = false;
    for (const auto &t : transactions)
    {
        if (t.getId() == id)
        {
            cout << "Transaction found:\n";
            t.displayTransaction();
            found = true;
            break; //  break after finding one
        }
    }
    if (found == false)
    {
        cout << "no transaction found with ID: " << id << "\n";
    }
}
void TransactionManager::saveTransactionsToCSV(const string &filename) const
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cerr << "Could not open file " << filename << " for writing." << endl;
        return;
    }

    file << "ID,Date,Amount,Category,Type" << endl; // header

    // Write each transaction as a CSV row
    for (const auto &t : transactions)
    {
        file << t.toCSV() << endl;
    }

    file.close();
    cout << "Transactions saved to " << filename << " successfully." << endl;
}

void TransactionManager::loadTransactionsFromCSV(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Could not open file " << filename << " for reading." << endl;
        return;
    }

    string line;

    // Skip the header line (e.g., "ID,Date,Amount,Category,Type")
    getline(file, line);

    // Read each transaction line by line
    while (getline(file, line))
    {
        Transaction t = Transaction::fromCSV(line); // Convert CSV line to Transaction object
        transactions.push_back(t);                  // Add the Transaction to the vector
    }

    file.close();
    cout << "Transactions loaded from " << filename << " successfully." << endl;
}
void TransactionManager::filterByCategory(const string &category) const
{
    cout<<category;
    bool found = false;
    for (const auto &t : transactions)
    {
        if (t.getCategory() == category)
        {
            t.displayTransaction();
            found = true;
        }
    }
    if (!found)
    {
        cout << "No transactions found for category: " <<category<< endl;
    }
    cout << endl;
}
void TransactionManager::filterByType(const string &type) const
{
    bool found = false;
    for (const auto &t : transactions)
    {

        if (t.getType() == type)
        {
            t.displayTransaction();
            found = true;
        }
    }
    if (found == false)
    {
        cout << "No transactions found for type: " << type << endl;
    }
    cout << endl;
}
void TransactionManager::overallSummary() const
{
    double income = 0;
    double expense = 0;
    double netBal = 0;

    for (const auto &t : transactions)
    {
        if (t.getType() == "expense")
        {
            expense += t.getAmount();
        }
        else
        {
            income += t.getAmount();
        }
    }
    netBal = income - expense;
    cout << "total income: " << income << endl;
    cout << "total expense: " << expense << endl;
    cout << "netBal: " << netBal << endl;
}
