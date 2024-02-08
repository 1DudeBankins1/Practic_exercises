#include "../headers/stock.h"
#include<iostream>
#include<cstring>

Stock::Stock()
{
    company = new char[5];
    std::strcpy(company, "NULL");
    shares = 0;
    share_val = 0;
    set_tot();
}

Stock::Stock(const char* co, int n, double pr)
{
    company = new char[std::strlen(co) + 1];
    std::strcpy(company, co);
    shares = n;
    share_val = pr;
    set_tot();
}

Stock::Stock(const Stock& st)
{
    delete[] company;
    company = new char[std::strlen(st.company) + 1];
    std::strcpy(company, st.company);
    shares = st.shares;
    share_val = st.share_val;
    set_tot();
}

Stock& Stock::operator=(const Stock& st)
{
    if(this == &st)
        return *this;
    delete[] company;
    company = new char[std::strlen(st.company) + 1];
    std::strcpy(company, st.company);
    shares = st.shares;
    share_val = st.share_val;
    set_tot();
    return *this;
}

Stock::~Stock()
{
    delete[] company;
}

void Stock::buy(int num, double price)
{
    shares += num;
    share_val = price;
    set_tot();
}

void Stock::sell(int num, double price)
{
    if(shares - num > 0){
        shares -= num;
        share_val = price;
        set_tot();
    }
    else
        std::cout << "Out of shares\n";
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

const Stock& Stock::topval(const Stock& s) const
{
    if(s.total_val > total_val)
        return s;
    else
        return *this;
}

std::ostream& operator<<(std::ostream& os, const Stock& st)
{
    os << "Company " << st.company << "\nShares: " << st.shares
       << "\nShare price: $" << st.share_val << "\nTotal worth: $"
       << st.total_val << "\n";
    return os;
}
