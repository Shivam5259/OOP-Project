#pragma once

#include <iostream>

using namespace std;

class Account;

class Card{
private:
    char* pass;
    char* card_number;
    
public:


};

class Debit_Card: public Card{
private:

public:
    void withdraw(Account &a, double amount);
};

class Credit_Card: public Card{
private:
    double borrowedMoney;
    double limit;
    char* deadline;
    double interestRate;

public:
    void withdraw(double amount);
    void returnBorrowedAmount(double amount);
};