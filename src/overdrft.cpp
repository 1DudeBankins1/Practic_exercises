#include "../headers/overdrft.h"
#include <iostream>

OverDraft::OverDraft(const char *s, long an, double bal,
                     double ml, double r) : Bank(s, an, bal)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

OverDraft::OverDraft(const Bank& ba, double ml, double r) : Bank(ba)
{
    maxLoan = ml;
    rate = r;
    owesBank = 0.0;
}

void OverDraft::ViewAcct() const
{
    std::ios_base::fmtflags initialState =
            std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout.setf(std::ios_base::showpoint);
    std::cout.precision(2);
    Bank::ViewAcct();
    std::cout << "Maximum loan: $" << maxLoan << std::endl;
    std::cout << "Owed to bank: $" << owesBank << std::endl;
    std::cout.setf(initialState);
}

void OverDraft::Withdraw(double amt)
{
    std::ios_base::fmtflags initialState =
            std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout.setf(std::ios_base::showpoint);
    std::cout.precision(2);
    double bal = Balance();
    if (amt <= bal)
        Bank::Withdraw(amt);
    else if (amt <= bal + maxLoan - owesBank)
    {
        double advance = amt - bal;
        owesBank += advance * (1.0 + rate);
        std::cout << "Bank advance: $" << advance << std::endl;
        std::cout << "Finance charge: $" << advance * rate << std::endl;
        Deposit(advance);
        Bank::Withdraw(amt);
    }
    else
        std::cout << "Credit limit exceeded. Transaction cancelled.\n";
    std::cout.setf(initialState);
}
