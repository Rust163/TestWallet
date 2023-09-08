#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include <algorithm>
#include "HeaderWallet.h"
// Функция для пополнения кошелька или карты
void Wallet::depositingMoney(Wallet& wallet, double amount) {
    Transaction transac;
    std::cout << "How much do you want to deposit?: ";
    std::cin >> transac.amount;
    wallet.transactions.push_back(transac);
}

// Функция для пополнения кошелька или карты
//void Wallet::deposit(Wallet& wallet, double amount) {
//    Transaction transaction;
//    transaction.category = "Deposit";
//    transaction.amount = amount;
//    transaction.timestamp = time(nullptr);
//    wallet.transactions.push_back(transaction);
//}

// Функция для внесения затрат
void Wallet::distributionOfCostsByCategory(Wallet& wallet, std::string category, double amount) {
    Transaction transac;
    std::cout << "Enter a category: ";
    std::cin >> transac.category;
    std::cout << "Enter the cost amount";
    std::cin >> transac.amount;
    transac.timestamp = time(nullptr);
    wallet.transactions.push_back(transac);
}

//void Wallet::addExpense(Wallet& wallet, std::string category, double amount) {
//    Transaction transaction;
//    transaction.category = category;
//    transaction.amount = -amount;
//    transaction.timestamp = time(nullptr);
//    wallet.transactions.push_back(transaction);
//}

// Функция для формирования отчета по затратам и категориям за указанный период
void Wallet::generateReport(Wallet& wallet, time_t startTime, time_t endTime) {
    std::vector<Transaction> filteredTransactions;
    for (const Transaction& transaction : wallet.transactions) {
        if (transaction.timestamp >= startTime && transaction.timestamp <= endTime) {
            filteredTransactions.push_back(transaction);
        }
    }

    std::cout << "Expense Report:" << std::endl;
    for (const Transaction& transaction : filteredTransactions) {
        std::cout << "Category: " << transaction.category << ", Amount: " << transaction.amount << std::endl;
    }
}

// Функция для формирования рейтинга по максимальным суммам затрат за указанный период
void  Wallet::generateTopExpenses(Wallet& wallet, time_t startTime, time_t endTime, int topCount) {
    std::vector<Transaction> filteredTransactions;
    for (const Transaction& transaction : wallet.transactions) {
        if (transaction.timestamp >= startTime && transaction.timestamp <= endTime && transaction.amount < 0) {
            filteredTransactions.push_back(transaction);
        }
    }

    std::sort(filteredTransactions.begin(), filteredTransactions.end(), [](const Transaction& a, const Transaction& b) {
        return a.amount < b.amount;
        });

    std::cout << "Top " << topCount << " Expenses:" << std::endl;
    for (int i = 0; i < topCount && i < filteredTransactions.size(); i++) {
        std::cout << "Category: " << filteredTransactions[i].category << ", Amount: " << filteredTransactions[i].amount << std::endl;
    }
}

// Функция для сохранения отчета в файл
void Wallet::saveReportToFile(Wallet& wallet, const std::string& fileName) {
    std::ofstream file(fileName);
    if (file.is_open()) {
        for (const Transaction& transaction : wallet.transactions) {
            file << "Category: " << transaction.category << ", Amount: " << transaction.amount << std::endl;
        }
        file.close();
        std::cout << "Report saved to file: " << fileName << std::endl;
    }
    else {
        std::cout << "Error opening file!" << std::endl;
    }
}