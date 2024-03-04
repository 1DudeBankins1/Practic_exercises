#include "../headers/cd.h"
#include <cstring>
#include<iostream>

Cd::Cd(char* s1, char* s2, int n, double x)
{
    std::strcpy(performers, s1);
    std::strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd()
{
    std::strcpy(performers, "Unknown");
    std::strcpy(label, "Empty");
    selections = 0;
    playtime = 0;
}

Cd::~Cd()
{

}

Cd::Cd(const Cd& d)
{
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
}

void Cd::report() const
{
    std::cout << "CD:\nPerformers: " << performers << "\nLabel: " << label
              << "\nSelections: " << selections << "\nPlaytime = " << playtime << " sec\n";
}

Cd& Cd::operator=(const Cd &d)
{
    if (&d == this)
        return *this;
    std::strcpy(performers, d.performers);
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
