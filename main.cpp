#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>

using namespace std;

class User;
class Bank;
class Admin;
class Account;
class Card;
class Transaction;

class User
{
private:
    string username;
    Account *account;
    int accountCount;
    int age;
    double salary;
    string address;
    string creationDate;

public:
    User(){}

    // bool verify(string s1, string s2)
    // {
    // }

    void createAcc()
    {                
    }

    // string &get_username()
    // {

    // }

    // string &get_pass()
    // {
    //     return ("");
    // }

    string getCurrentDate() {
        time_t now = time(0);
        char buf[20];
        strftime(buf, sizeof(buf), "%d-%m-%Y", localtime(&now));
        return string(buf);
    }

    void operator=(User u)
    {
    }
};

class Admin
{
};

class Account{
private:
    double balance;
    string acc_number;
    string pass;
    Transaction *transaction_history;
    int transactionCount;
    Card *card;
    int cardCount;

public:
    void withdraw(double amount){
        if(balance >= amount){
            balance-=amount;
            cout<<"You have successfully withdrawn "<<amount<<" from your account and your new account balance is: "<<balance<<endl;
        }
        else{
            cout<<"Insufficient Balance!\nPlease Enter Valid Amount"<<endl;
        }
    }

    void deposit(double amount){
        if(amount >= 0){
            balance+=amount;
        }
        else{
            //invalid amount
        }
    }
};

class Current: public Account{
private:

public:
};

class Saving: public Account{
private:
    double interestRate;


public:
};

class Card{
private:
    string pass;
    string card_number;
    Transaction *transaction_history;
    int transactionCount;
    
public:
};

class Debit_Card: public Card{
private:

public:
};

class Credit_Card: public Card{
private:

public:
};

class Transaction{
private:
    string type;
    double amount;
    string date;

public:
};

class Bank
{
private:
    User user;
    Admin admin;
    const int encryption_key=120;


public:
    void encrypt_decrypt(string &s)
    {
        for (int i = 0; i < s.length(); i++)
        {
            s[i] ^= Bank::encryption_key;
        }
    }

    void createAcc()
    {
        cin.ignore();
        cout << "Enter Username: ";
        // getline(cin, user.get_username());
        cout << "Enter Password: ";
        // cin >> user.get_pass();
    }

    void start()
    {
        int n;
        cout << "Enter:\n1.Log In\n2.Ceate Account\nAny Other Key to Exit : ";
        cin >> n;

        switch (n)
        {
        case 1:
        {
            string s1, s2;
            cin.ignore();
            cout << "Enter Username: ";
            getline(cin, s1);
            cout << "Enter Password: ";
            cin >> s2;
            encrypt_decrypt(s2);

            ifstream file("user.txt");

            if (file.is_open())
            {
                User u;
                while (file.read(reinterpret_cast<char *>(&u), sizeof(u)))
                {
                    // if (u.verify(s1, s2))
                    // {
                    //     cout << "Successfully Logged In!\n";
                    //     user = u;
                    //     break;
                    // }
                }
                cout << "Username or Password didn't matched!\nPlease Try Again!";
            }
            else
            {
                cout << "Error Opening File:(" << endl;
            }
            file.close();
            break;
        }

        case 2:
        {
            user.createAcc();
            ofstream file("user.txt");

            if (file.is_open())
            {
                file.write(reinterpret_cast<char *>(&user), sizeof(user));
                cout << "Account Created Successfully!" << endl;
            }
            else
            {
                cout << "Error Opening File:(" << endl;
            }
            break;
        }

        default:
            cout << "Terminating the program!";
            exit(0);
        }
    }
};

int main()
{
    // Bank bank;
    // bank.start();
    User u;
    cout<<u.getCurrentDate();
}