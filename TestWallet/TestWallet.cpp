#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>
#include "HeaderWallet.h"
#include "Menu.h"

int main() {
    Wallet wallet;
    wallet.name = "My Wallet";
    mainMenu();
    //wallet.deposit(wallet, 1000.0);
    //wallet.addExpense(wallet, "Food", 50.0);
    //wallet.addExpense(wallet, "Entertainment", 100.0);
    //wallet.addExpense(wallet, "Shopping", 200.0);
    //
    //time_t currentTime = time(nullptr);
    //time_t startTime = currentTime - (7 * 24 * 60 * 60); // Неделя назад
    //time_t endTime = currentTime;
    //
    //wallet.generateReport(wallet, startTime, endTime);
    //wallet.generateTopExpenses(wallet, startTime, endTime, 3);
    //
    //wallet.saveReportToFile(wallet, "report.txt");
}