#include "func.h"

void Set_str(CandyBar& sweet, const std::string nme, double w, unsigned int c)
{
    sweet.name = nme;
    sweet.weight = w;
    sweet.cal = c;
}

void Print_str(CandyBar& sweet)
{
    std::cout << "Candy of " << sweet.name << " has weight = " << sweet.weight
              << " and calories = " << sweet.cal << std::endl;
}
