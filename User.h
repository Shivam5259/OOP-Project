#pragma once

#include <iostream>

using namespace std;

class User{
protected:
    string name;
    string username;
    string password;

public:
    User(string u, string pass) : username(u), password(pass) {}
    User() {}
    

    virtual void displayMenu()=0;

    bool verifyPass(string pass);

    string getUsername();

    string getPass();

    void operator=(User *u);
};