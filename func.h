#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <cstring>

struct CandyBar
{
    std::string name;
    double weight;
    unsigned int cal;
};

void Set_str(CandyBar& sweet, const std::string nme = "Millenium Munch", double w = 2.85, unsigned int c = 350);

void Print_str(CandyBar& sweet);

#endif // FUNC_H
