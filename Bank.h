#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
#include "Account.h"
#include "Card.h"
#include "User.h"
#include "AccountHolder.h"

using namespace std;

string getCurrentDate();
int calculateAge(string, string);
chrono::system_clock::time_point stringToDate(string& dateStr);

class Bank
{
private:
    User *user;
    // Admin admin;
    const int encryption_key=120;


public:
    void encrypt_decrypt(string &s);

    void createAcc();

    void displayMenu();

    void log_in(string name, string pass);

    void createAccount();
};

#endif