#include "Bank_bill.h"

Bank_Bill::Bank_Bill()
{
    investor_name = "Noname";
    bill_number = "Unknown";
    saldo = 0.0;
}

Bank_Bill::Bank_Bill(std::string inv_name, std::string bill_num, double sald)
{
    investor_name = inv_name;
    bill_number = bill_num;
    saldo = sald;
}

Bank_Bill::~Bank_Bill()
{
    std::cout << investor_name << "'s bill destroyed!" << std::endl;
}

void Bank_Bill::show()
{
    std::cout << "The bill number of " << investor_name << " is " << bill_number << ", it has " << saldo << "$\n";
}

void Bank_Bill::invest(double sum)
{
    saldo += sum;
}

void Bank_Bill::withdraw(double sum)
{
    saldo -= sum;
}
