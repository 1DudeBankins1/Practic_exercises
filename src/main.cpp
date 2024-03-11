#include <iostream>
#include "../headers/overdrft.h"

const int ASIZE = 3;
const int MAX = 35;

inline void EatLine() {while (std::cin.get() != '\n') continue;}

int main()
{
    Bank * baps[ASIZE] ;
    char name[MAX] ;
    long acctNum;
    double balance;
    int acctType;
    int i;

    for (i = 0; i < ASIZE; i++)
    {
        std::cout << "Enter client’s name: ";
        std::cin.get(name ,MAX);
        EatLine() ;
        std::cout << "Enter client's account number: ";
        std::cin >> acctNum;
        std::cout << "Enter client’s initial balance: ";
        std::cin >> balance;
        std::cout << "Enter 1 for Brass Account, 2 for Brass Plus " << "Account: ";
        std::cin >> acctType;
        EatLine();
        if (acctType == 2) baps[i] = new OverDraft(name, acctNum, balance);
        else
        {
            baps[i] = new BankAccount(name, acctNum, balance);
            if (acctType != 1) std::cout << "I/1l interpret that as a 1.\n";
        }
    }

    for (i = 0; i < ASIZE; i++)
    {
        baps[i]->ViewAcct();
        std::cout << std::endl;
    }

    std::cout << "Bye!\n";
    return 0;
}
