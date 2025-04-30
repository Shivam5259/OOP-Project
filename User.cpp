#include <iostream>
#include "User.h"

using namespace std;

// User::User(string u, string pass) : username(u), password(pass) {}
// User::User() {}

bool User::verifyPass(string pass)
{
    return (password == pass) ? true : false;
}

string User::getUsername()
{
    return username;
}

string User::getPass()
{
    return password;
}

void User::operator=(User *u)
{
    username = u->username;
    password = u->password;
}