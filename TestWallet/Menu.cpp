#include <iostream>
#include <windows.h>
#include <conio.h>
#include "HeaderWallet.h"
#include "Menu.h"

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
void d(short x, short y) {
    SetConsoleCursorPosition(h, { x,y });
}
void ConsoleCursorVisible(short size, bool show = false) {
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(h, &structCursorInfo);
    structCursorInfo.bVisible = show;
    structCursorInfo.dwSize = size;
    SetConsoleCursorInfo(h, &structCursorInfo);
}

void mainMenu() {
    Wallet wallet; time_t startTime{ 0 }; time_t endTime{ 0 }; int topCount{ 0 }; double amount{ 0 };
    std::string T[] = { "1) Deposit money", "2) Show deposit", "3) Show report", "4) Add user", "4) Exit" };
    char aT = 0;
    char c;
    while (true) {
        char x = 50, y = 12;
        d(x, y);
        for (char i = 0; i < size(T); i++) {
            if (i == aT) {
                SetConsoleTextAttribute(h, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            }
            else {
                SetConsoleTextAttribute(h, FOREGROUND_RED);
            }
            d(x, y++);
            std::cout << T[i] << std::endl;
        }
        c = _getch();
        if (c == -32) {
            c = _getch();
        }
        switch (c) {
        case ESC:
            exit(0);
        case UP:
            if (aT > 0) {
                --aT;
            }
            break;
        case DOWN:
            if (aT < size(T) - 1) {
                ++aT;
            }
            break;
        case ENTER:
            switch (aT) {
            case 0:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                wallet.depositingMoney(wallet, amount);
                system("CLS");
                break;
            }
            case 1:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                wallet.generateTopExpenses(wallet, startTime, endTime, topCount);
                system("CLS");
                break;
            }
            case 2:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 3:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                
                //system("CLS");
                break;
            }
            case 4:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 5:
            {

                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                //regUser.addUserCardInfo();
                
                system("CLS");
                break;
            }
            case 6:
            {
                system("CLS");
                d(x, y);
                SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
                std::cout << "���������� \"" << T[aT] << "\"";
                system("CLS");
                break;
            }
            case 7:
            {
                exit(0);
                break;
            }
            default:
                std::cout << "" << (char)c << std::endl;
            }
        }
    }
}