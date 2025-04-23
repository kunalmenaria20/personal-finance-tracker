#include "TransactionManager.h"
#include <iostream>
using namespace std;
void TransactionManager:: addTransaction(Transaction& t){
    // for(const auto& tr : transactions) {
    //     if(tr.getId()==t.getId()){
    //         cout<<"Error: Transaction with ID "<<t.getId()<<" already exist.\n";
    //         return;
    //     }
        
    // };
    t.setId(nextTransactionId++);
    transactions.push_back(t);

    cout<<"Transaction added successfully.\n";
    
}
void TransactionManager::deleteTransactionByID(int to_deleteId){
    bool found= false;
    for(auto it =transactions.begin(); it !=transactions.end();++it){
        if(it->getId()==to_deleteId){
        transactions.erase(it);
        found=true;
        cout<<"Transaction successfully deleted.\n";
        break;
        }
    }
    if(found==false){
        cout<<"no transaction found with ID: "<<to_deleteId<<"\n";
    }
}
void TransactionManager::displayAllTransactions() const{
    for(const Transaction&t :transactions){    //iteration in the transcation to get to the every element//
    t.displayTransaction();
    cout<<endl;
}
}
void TransactionManager::searchTransactionByID(int id) {
    bool found = false;
    for (const auto& t : transactions) {
        if (t.getId() == id) {
            std::cout << "Transaction found:\n";
            t.displayTransaction();
            found = true;
            break;            //  break after finding one
        }
    }
    if(found==false){
        cout<<"no transaction found with ID: "<<id<<"\n";
    
}
}





