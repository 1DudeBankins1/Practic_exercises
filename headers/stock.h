#ifndef STOCK_H
#define STOCK_H

#include<iostream>

class Stock
{
private:
    char* company;
    int shares;
    double share_val;
    double total_val;
    void set_tot()
        {total_val = shares * share_val;}

public:
    Stock();
    Stock(const char* co, int n, double pr);
    Stock(const Stock& st);
    ~Stock();

    Stock& operator=(const Stock& st);

    void buy(int num, double price);
    void sell(int num, double price);
    void update(double price);
    const Stock& topval(const Stock& s) const;

    friend std::ostream& operator<<(std::ostream& os, const Stock& st);
};

#endif // STOCK_H
