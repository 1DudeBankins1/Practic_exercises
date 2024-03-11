#include "../headers/bankaccnt.h"
#include <iostream>
#include <cstring>

Bank::Bank(const char *s, long an, double bal)
{
    std::strncpy(fullname, s, MAX-1);
    fullname[MAX - 1] = '\0';
    acctNum = an;
    balance = bal;
}

Bank::Bank(const Bank& ba)
{
    std::strncpy(fullname, ba.fullname, MAX-1);
    fullname[MAX - 1] = '\0';
    acctNum = ba.acctNum;
    balance = ba.balance;
}

void Bank::Deposit(double amt)
{
    balance += amt;
}

void Bank::Withdraw(double amt)
{
    if (amt <= balance)
        balance -= amt;
    else
        std::cout << "Withdrawal amount of $" << amt
                  << " exceeds your balance.\nWithdrawal canceled.\n";
}

double Bank::Balance() const
{
    return balance;
}

void Bank::ViewAcct() const
{
    std::ios_base::fmtflags initialState = std::cout.setf(std::ios_base::fixed,
    std::ios_base::floatfield);
    std::cout.setf(std::ios_base::showpoint);
    std::cout.precision(2);
    std::cout << "Client: " << fullname << std::endl;
    std::cout << "Account Number: " << acctNum << std::endl;
    std::cout << "Balance: $" << balance << std::endl;
    std::cout.setf(initialState);
}

BankAccount::BankAccount(const char *s, long an, double bal) : Bank(s, an, bal)
{

}

BankAccount::BankAccount(const Bank& ba) : Bank(ba)
{

}

void BankAccount::Withdraw(double amt)
{
    Bank::Withdraw(amt);
}

void BankAccount::ViewAcct() const
{
    Bank::ViewAcct();
}
