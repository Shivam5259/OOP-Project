#include <iostream>
#include <cstring>
#include <vector>
#include <fstream>
#include <ctime>
#include <chrono>
#include <sstream>
#include <iomanip>
#include "C:\raylib\raylib\src\raylib.h"
#include "Bank.h"
#include "Account.h"
#include "AccountHolder.h"
#include "Admin.h"
#include "User.h"
#include "Card.h"

using namespace std;

void Bank::encrypt_decrypt(char *(&s))
{
    for (int i = 0; s[i] != '\0'; i++)
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
        char username[25];
        cout << "Enter User Name: ";
        cin >> username;

        char *password = new char[25];
        cout << "Enter Password: ";
        cin >> password;

        encrypt_decrypt(password);

        log_in(username, password);
        delete[] password;
        drawInputWindow();

        break;
    }

    case 2:
    {
        createAccount();
    }
    }
}

void Bank::log_in(char *name, char *pass)
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
            if (!strcmp(u->getUsername(), name))
            {

                if (u->verifyPass(pass) == true)
                {
                    user = u;
                    cout << "Logged In Successfully!" << endl;
                    delete u;
                    file.close();
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
    char *pass = new char[25];
    char name[25];
    strcpy(name, "Shivam");
    strcpy(pass, "shivam123");
    encrypt_decrypt(pass);
    user = new AccountHolder(name, pass);

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
    delete[] pass;
}

char *getCurrentDate()
{
    time_t now = time(0);
    char *buf = new char[10];
    strftime(buf, sizeof(buf), "%d-%m-%Y", localtime(&now));
    return buf;
}

chrono::system_clock::time_point stringToDate(string &dateStr)
{
    istringstream ss(dateStr);
    tm tm = {};
    ss >> get_time(&tm, "%Y-%m-%d");
    return chrono::system_clock::from_time_t(mktime(&tm));
}

int calculateAge(string current, string deadline)
{
    auto time1 = stringToDate(current);
    auto time2 = stringToDate(deadline);

    auto duration = time2 - time1;
    int days = chrono::duration_cast<chrono::seconds>(duration).count() / (60 * 60 * 24);
    cout << "Difference: " << days << " days" << endl;

    return days;
}

void Bank::drawInputWindow()
{
    bool exit = false;
    Rectangle UsernameBox = {300, 195, 200, 30};
    Rectangle PasswordBox = {300, 245, 200, 30};
    Rectangle Login_Button = {300, 300, 90, 40};
    Rectangle Exit_Button = {410, 300, 90, 40};
    static int x = 0;

    while (!exit || WindowShouldClose())
    {
        bool mouseOnUsername = CheckCollisionPointRec(GetMousePosition(), UsernameBox);
        bool username_clicked = false;
        bool mouseOnPassword = CheckCollisionPointRec(GetMousePosition(), PasswordBox);
        bool password_clicked=false;
        bool mouseOnLogin = CheckCollisionPointRec(GetMousePosition(), Login_Button);
        exit = CheckCollisionPointRec(GetMousePosition(), Exit_Button);

        BeginDrawing();

        if(!username_clicked || !password_clicked){
            DrawText("Username:", 200, 200, 20, BLACK);
            DrawRectangleRec(UsernameBox, LIGHTGRAY);

            DrawText("Password:", 200, 250, 20, BLACK);
            DrawRectangleRec(PasswordBox, LIGHTGRAY);

            DrawRectangleRec(Login_Button, SKYBLUE);
            DrawText("Login", 320, 310, 20, BLACK);

            DrawRectangleRec(Exit_Button, RED);
            DrawText("Exit", 440, 310, 20, BLACK);
        }

        if (mouseOnUsername && IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
        {
            username_clicked = true;
        }

        
        if (username_clicked)
        {
            if ((x++) % 2 == 0)
                DrawText("|", 302, 200, 20, BLACK);
            else
                DrawText(" ", 302, 200, 20, BLACK);

            DrawRectangleRec(UsernameBox, LIGHTGRAY);
        }

        EndDrawing();
    }
    return;
}