#pragma once

#include <iostream>
#include "Account.h"
#include "User.h"
using namespace std;

class AccountHolder: public User
{
private:
    Account *account;
    int accountCount;
    int age;
    double salary;
    string address;
    string creationDate;
    string contact;
    string accountType;

public:
    AccountHolder(string user, string pass);
    AccountHolder();

    // bool verify(string s1, string s2);

    void createAcc();

    // string &get_username();

    // string &get_pass();
    void displayInfo();

    void displayMenu();
};