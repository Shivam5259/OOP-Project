#include <iostream>
#include "AccountHolder.h"
using namespace std;

AccountHolder::AccountHolder(char* user, char* pass) : User(user, pass) {}
AccountHolder::AccountHolder() {}

// bool verify(string s1, string s2)
// {
// }

void AccountHolder::createAcc()
{
}

// string &get_username()
// {

// }

// string &get_pass()
// {
//     return ("");
// }

void AccountHolder::displayInfo()
{
    cout << "\n\nDisplaying Account Holder Information: \n";
    cout << "Name: " << name << endl;
    cout << "User Name: " << username << endl;
    if (accountCount == 1)
    {
        cout << "Account Type: " << accountType << endl;
    }
    else
    {
        cout << "Account Type 1: Current Account" << endl;
        cout << "Account Type 2: Saving Account" << endl;
    }
    // cout<<"Account Number: "<<account->getAccNumber()<<endl;
    cout << "Age: " << age << endl;
    cout << "Contact Information: " << contact << endl;
    cout << "Address: " << address << endl;
}

void AccountHolder::displayMenu()
{
    int n;
    cout << "Choose Required Option: \n";
    cout << "1. Display Account Information\n";
    cout << "";

    switch (n)
    {
    case 1:
    {
        displayInfo();
    }
    }
}