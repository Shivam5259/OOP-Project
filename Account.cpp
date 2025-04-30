#include <iostream>
#include <cstring>
#include <fstream>
#include "Account.h"

using namespace std;

void Account::withdraw(double amount)
{
    if (balance >= amount)
    {
        balance -= amount;
        cout << "You have successfully withdrawn " << amount << " from your account and your new account balance is: " << balance << endl;
    }
    else
    {
        cout << "Insufficient Balance!\nPlease Enter Valid Amount" << endl;
    }
}

void Account::deposit(double amount)
{
    if (amount >= 0)
    {
        balance += amount;
    }
    else
    {
        // invalid amount
    }
}

string Account::getAccNumber()
{
    return acc_number;
}

Transaction::Transaction(){}

Transaction::Transaction(string s, string t, double a, string d): source(s), type(t), amount(a), date(d) {
    file=nullptr;
}

void Transaction::write(){
    file.open("Transaction.dat", ios::binary | ios::app);
    if(!file.is_open()){
        cout<<"Unable to open!"<<endl;
        return;
    }
    file.write(reinterpret_cast<char *>(this), sizeof(Transaction));
    file.close();
}

void Transaction::read(string source){
    file.open("Transaction.dat", ios::binary | ios::in);

    if(file.is_open()==false){
        cout<<"Unable to open!"<<endl;
        return;
    }

    int n=0;

    while(file.read(reinterpret_cast<char *> (this), sizeof(Transaction))){
        if(this->source == source){
            cout<<"Transaction Number: "<<++n<<endl;
            cout<<this<<endl;
        }
    }
    file.close();
}

ostream& operator<<(ostream& out, Transaction &t){
    return(out<<"Source: "<<t.source<<"\tType: "<<t.type<<"\tAmount: "<<t.amount<<"Date: "<<t.date);
}

Transaction::~Transaction(){}