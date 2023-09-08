#pragma once
#include <iostream>
#include <ctime>
#include <vector>
#include <string>
// Класс для хранения информации о транзакции
class Transaction {
public:
    std::string category;
    double amount;
    time_t timestamp;

    Transaction() {}

    
    
};

// Класс для хранения информации о кошельке или карте
class Wallet : public Transaction  {
public:
    std::string name;
    std::vector<Transaction> transactions;

    Wallet(){}
    void generateReport(Wallet& wallet, time_t startTime, time_t endTime);
    void saveReportToFile(Wallet& wallet, const std::string& fileName);
    //void deposit(Wallet& wallet, double amount);
    //void addExpense(Wallet& wallet, std::string category, double amount);
    void depositingMoney(Wallet& wallet, double amount);
    void distributionOfCostsByCategory(Wallet& wallet, std::string category, double amount);
    void generateTopExpenses(Wallet& wallet, time_t startTime, time_t endTime, int topCount);
};