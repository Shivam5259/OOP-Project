#pragma once

#include <iostream>
#include <fstream>
#include "Card.h"

using namespace std;

class Transaction{
    private:
        string source;
        string type;
        double amount;
        string date;
        fstream file;
    
    public:

    Transaction();
    Transaction(string s, string t, double a, string d);
    void write();
    void read(string);
    friend ostream& operator<<(ostream& out, Transaction &t);

    ~Transaction();
};

class Account{
private:
    double balance;
    string acc_number;
    string pass;
    Card *card;
    int cardCount;

public:
    void withdraw(double amount);
    void transfer(Account &a, double amount);
    void deposit(double amount);

    string getAccNumber();
};

class Current: public Account{
private:

public:
};

class Saving: public Account{
private:
    double interestRate;


public:
};