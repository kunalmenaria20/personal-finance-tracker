#include "Transaction.h"

Transaction::Transaction(const string &tDate, double tAmt, const string &tCatg, const string &tType)
    : date(tDate), amount(tAmt), category(tCatg), type(tType) {} // constructor

void Transaction::displayTransaction() const
{
    cout << "Id: " << id << " || " << "Date: " << date << " || " << "Amount: " << amount << " || "
        << "Category: " << category << " || " << "Type: " << type << endl;
}
int Transaction::getId() const
{
    return id;
}
void Transaction::setId(int newId)
{
    id = newId;
}
string Transaction::toCSV() const
{
    stringstream ss;
    ss << id << "," << date << "," << amount << "," << category << "," << type;
    return ss.str();
}
Transaction Transaction::fromCSV(const string &line)
{
    stringstream ss(line);
    string item;
    Transaction t("", 0.0, "", ""); // temporary default values

    getline(ss, item, ',');
    t.setId(stoi(item));

    getline(ss, item, ',');
    t.date = item;

    getline(ss, item, ',');
    t.amount = stod(item);

    getline(ss, item, ',');
    t.category = item;

    getline(ss, item, ',');
    t.type = item;

    return t;
}
string Transaction::getCategory() const
{
    return category;
}
string Transaction::getType() const
{
    return type;
}
double Transaction::getAmount() const
{
    return amount;
}
