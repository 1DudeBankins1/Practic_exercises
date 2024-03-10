#include "../headers/cd.h"
#include <cstring>
#include<iostream>

Cd::Cd(char* s1, char* s2, int n, double x)
{
    performers = new char[std::strlen(s1)+1];
    std::strcpy(performers, s1);
    label = new char[std::strlen(s2)+1];
    std::strcpy(label, s2);
    selections = n;
    playtime = x;
}

Cd::Cd()
{
    performers = new char[8];
    std::strcpy(performers, "Unknown");
    label = new char[6];
    std::strcpy(label, "Empty");
    selections = 0;
    playtime = 0;
}

Cd::~Cd()
{
    delete[] performers;
    delete[] label;
}

Cd::Cd(const Cd& d)
{
    performers = new char[std::strlen(d.performers)+1];
    std::strcpy(performers, d.performers);
    label = new char[std::strlen(d.label)+1];
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
    delete[] performers;
    performers = new char[std::strlen(d.performers)+1];
    std::strcpy(performers, d.performers);
    delete[] label;
    label = new char[std::strlen(d.label)+1];
    std::strcpy(label, d.label);
    selections = d.selections;
    playtime = d.playtime;
    return *this;
}
