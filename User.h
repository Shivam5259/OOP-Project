#pragma once

#include <iostream>

using namespace std;

class User{
protected:
    char name[25];
    char username[25];
    char password[25];

public:
    User(char* u, char* pass);
    User();
    

    virtual void displayMenu()=0;

    bool verifyPass(char* pass);

    char* getUsername();

    char* getPass();

    void operator=(User *u);

    virtual ~User();
};