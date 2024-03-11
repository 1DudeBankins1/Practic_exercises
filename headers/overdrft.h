#ifndef OVERDRAFT_H
#define OVERDRAFT_H

#include "../headers/bankaccnt.h"

class OverDraft : public Bank
{
private:
    double maxLoan;
    double rate;
    double owesBank;
public:
    OverDraft(const char *s = "Nullbody", long an = -1, double bal = 0.0,
              double ml = 500, double r = 0.1);
    OverDraft(const Bank& ba, double ml = 500, double r = 0.1);
    void ViewAcct() const override;
    void Withdraw(double amt) override;
    void ResetMax(double m) {maxLoan = m;}
    void ResetRate(double r) {rate = r;}
    void ResetOwes() {owesBank = 0;}
};

#endif // OVERDRAFT_H
