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

int main(){
    Transaction t("Account", "Withdraw", 120000, "12-09-2025");

    t.write();
    Transaction t1;
    t1.read("Account");
}