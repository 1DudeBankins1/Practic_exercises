#ifndef BANK_BILL_H
#define BANK_BILL_H

#include <iostream>
#include <cstring>

class Bank_Bill
{
public:

    Bank_Bill();
    Bank_Bill(std::string investor_name, std::string bill_num, double saldo = 0.0);
    ~Bank_Bill();

    void show();
    void invest(double sum);
    void withdraw(double sum);

private:

    std::string investor_name;
    std::string bill_number;
    double saldo;

};

#endif // BANK_BILL_H
