#include <iostream>
#include <cstdlib>
#include "../headers/stock.h"

const int STKS = 4;

int main(int argc, char* argv[])
{
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolitic Obelisks", 130, 3.25),
        Stock("Fleep Interprices", 60, 6.5)
    };

    std::cout.precision(2);
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout.setf(std::ios_base::showpoint);
    std::cout << "Stock holdings:\n";
    int st;
    for (st = 0; st < STKS; ++st)
        std::cout << stocks[st];
    Stock top = stocks[0];
    for (st = 1; st < STKS; ++st)
        top = top.topval(stocks[st]);
    std::cout << "Most valuable holding:\n";
    std::cout << top;
    return 0;
}
