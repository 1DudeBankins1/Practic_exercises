#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

class Bank
{
private:
    enum {MAX = 35};
    char fullname[MAX];
    long acctNum;
    double balance;
public:
    Bank(const char *s = "Nullbody", long an = -1, double bal = 0.0);
    Bank(const Bank& ba);
    virtual void Withdraw(double amt) = 0;
    virtual void ViewAcct() const = 0;
    void Deposit(double amt);
    double Balance() const;
};

class BankAccount : public Bank
{
private:

public:
    BankAccount(const char *s = "Nullbody", long an = -1, double bal = 0.0);
    BankAccount(const Bank& ba);
    void Withdraw(double amt) override;
    void ViewAcct() const override;
};

#endif // BANKACCOUNT_H
