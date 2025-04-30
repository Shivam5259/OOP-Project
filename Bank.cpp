#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "Bank.h"
#include "Account.h"
#include "AccountHolder.h"
#include "Admin.h"
#include "User.h"
#include "Card.h"


using namespace std;

void Bank::encrypt_decrypt(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        s[i] ^= encryption_key;
    }
}

void Bank::createAcc()
{
    cin.ignore();
    cout << "Enter Username: ";
    // getline(cin, user.get_username());
    cout << "Enter Password: ";
    // cin >> user.get_pass();
}

void Bank::displayMenu()
{
    int n;
    cout << "Choose Required Options: \n";
    cout << "1. Log In\n";
    cout << "2. Create Account\n";
    cout << "3. Log In as Admin\n";

    cin >> n;

    switch (n)
    {
    case 1:
    {
        string username;
        cout << "Enter User Name: ";
        cin >> username;

        string password;
        cout << "Enter Password: ";
        cin >> password;

        encrypt_decrypt(password);

        log_in(username, password);

        break;
    }

    case 2:
    {
        createAccount();
    }
    }
}

void Bank::log_in(string name, string pass)
{
    User *u = new AccountHolder;
    ifstream file;
    file.open("User.dat", ios::binary);

    if (file.is_open() == false)
    {
        cout << "Error File Opening!" << endl;
        return;
    }
    else
    {
        while (file.read(reinterpret_cast<char *>(u), sizeof(AccountHolder)))
        {

            if (u->getUsername() == name)
            {
                if (u->verifyPass(pass) == true)
                {
                    user = u;
                    cout << "Logged In Successfully!" << endl;
                    return;
                }
            }
        }
        cout << "Invalid Username or Password:(\nPlease Enter Correct Information!" << endl;
    }
    file.close();
    return;
}

void Bank::createAccount()
{
    string pass = "shivam123";
    encrypt_decrypt(pass);
    user = new AccountHolder("Shivam", pass);

    ofstream file("User.dat", ios::binary);

    if (file.is_open() == false)
    {
        cout << "Error File Opening!" << endl;
        return;
    }
    else
    {
        file.write(reinterpret_cast<char *>(user), sizeof(AccountHolder));
    }
    file.close();
}

string getCurrentDate()
{
    time_t now = time(0);
    char buf[20];
    strftime(buf, sizeof(buf), "%d-%m-%Y", localtime(&now));
    return string(buf);
}

chrono::system_clock::time_point stringToDate(string& dateStr){
    istringstream ss(dateStr);
    tm tm = {};
    ss >> get_time(&tm, "%Y-%m-%d");
    return chrono::system_clock::from_time_t(mktime(&tm));
}

int calculateAge(string current, string deadline){
    auto time1 = stringToDate(current);
    auto time2 = stringToDate(deadline);

    auto duration = time2-time1;
    int days = chrono::duration_cast<chrono::seconds>(duration).count()/(60*60*24);
    cout << "Difference: " << days << " days" << endl;

    return days;
}