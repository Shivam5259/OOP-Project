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
    char* address;
    char* creationDate;
    char* contact;
    char* accountType;

public:
    AccountHolder(char* user, char* pass);
    AccountHolder();

    // bool verify(string s1, string s2);

    void createAcc();

    // string &get_username();

    // string &get_pass();
    void displayInfo();

    void displayMenu();
};