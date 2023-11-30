#include "plorg.h"
#include <cstring>
#include <iostream>

Plorg::Plorg(char nme[SIZE], int cci)
{
    std::strncpy(this->name, nme, SIZE);
    this->ci = cci;
}

void Plorg::set_ci(int cci)
{
    this->ci = cci;
}

void Plorg::show() const
{
    std::cout << "CI of " << this->name << " equals " << this->ci << std::endl;
}
