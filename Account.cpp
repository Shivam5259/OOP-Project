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

char* Account::getAccNumber()
{
    return acc_number;
}

Transaction::Transaction(){}

Transaction::Transaction(char* acc, char* s, char* t, double a, char* d){
    strncpy(acc_no, acc, sizeof(acc_no));
    strncpy(source, s, sizeof(source));
    strncpy(type, t, sizeof(type));
    amount=a;
    strncpy(date, d, sizeof(date));
}

void Transaction::write(){
    ofstream file("Transaction.dat", ios::binary | ios::app);
    if(!file.is_open()){
        cout<<"Unable to open!"<<endl;
        return;
    }
    file.write(reinterpret_cast<char *>(this), sizeof(Transaction));
    file.close();
}

void Transaction::read(char* acc, char* source){
    ifstream file("Transaction.dat", ios::binary | ios::in);

    if(!file.is_open()){
        cout<<"Unable to open!"<<endl;
        return;
    }

    int n=0;
    Transaction temp;

    while(file.read(reinterpret_cast<char *> (&temp), sizeof(Transaction))){

        if(!strcmp(temp.acc_no, acc) && !strcmp(temp.source, source)){
            cout<<"Transaction Number: "<<++n<<endl;
            cout<<temp<<endl;
        }
    }
    file.close();
}

ostream& operator<<(ostream& out, Transaction &t){
    return(out<<"Source: "<<t.source<<"\tType: "<<t.type<<"\tAmount: "<<t.amount<<"\tDate: "<<t.date);
}

Transaction::~Transaction(){}