#include "TransactionManager.h"
#include <iostream>
using namespace std;
void TransactionManager:: addTransaction(const Transaction& t){
    transactions.push_back(t);
}
void TransactionManager::deleteTransactionByID(int to_deleteId){
    bool found= false;
    for(auto it =transactions.begin(); it !=transactions.end();++it){
        if(it->getId()==to_deleteId){
        transactions.erase(it);
        found=true;
        cout<<"Transaction successfully deleted.";
        }
    }
    if(found==false){
        cout<<"Invalid Transaction ID"<<endl;
    }
}
void TransactionManager::displayAllTransactions() const{
    for(const Transaction&t :transactions){    //iteration in the transcation to get to the every element//
    t.displayTransaction();
    cout<<endl;
}
}
void TransactionManager::searchTransactionByID(int id){
for(auto it=transactions.begin();it!=transactions.end();++it){
    bool found=false;
    if (it->getId() == id) {
        cout << "Transaction found:\n";
        it->displayTransaction();
    }
    if(found==false){
        cout<<"no transaction found";
    }
}
}





