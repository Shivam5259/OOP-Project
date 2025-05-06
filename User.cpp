#include <iostream>
#include <cstring>
#include "User.h"

using namespace std;

User::User(char* u, char* pass){
    strcpy(username, u);
    strcpy(password, pass);
}

User::User(){}

User::~User(){}


bool User::verifyPass(char* pass)
{
    return (!strcmp(password, pass)) ? true : false;
}

char* User::getUsername()
{
    return username;
}

char* User::getPass()
{
    return password;
}

void User::operator=(User *u)
{
    strcpy(username, u->getUsername());
    strcpy(password, u->getPass());
}