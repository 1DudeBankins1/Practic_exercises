#include "../headers/cow.h"
#include <iostream>
#include <cstring>

Cow::Cow()
{
    strcpy(name, " ");
    hobby = new char[1];
    hobby = NULL;
    weight = 0.0;
}

Cow::Cow(const char* nm, const char* ho, double wt)
{
    strncpy(name, nm, strlen(nm));
    hobby = new char[strlen(ho)+1];
    strncpy(hobby, ho, strlen(ho));
    weight = wt;
}

Cow::Cow(const Cow& c)
{
    strncpy(name, c.name, strlen(c.name));
    hobby = new char[strlen(c.hobby)+1];
    strncpy(hobby, c.hobby, strlen(c.hobby));
    weight = c.weight;
}

Cow::~Cow()
{
    delete[] hobby;
}

Cow& Cow::operator=(const Cow& c)
{
    if(this == &c)
        return *this;

    strncpy(name, c.name, strlen(c.name));
    delete[] hobby;
    hobby = new char[strlen(c.hobby)+1];
    strncpy(hobby, c.hobby, strlen(c.hobby));
    weight = c.weight;

    return *this;
}

void Cow::ShowCow()
{
    if (hobby != NULL)
        std::cout << "The cow " << name << " has " << hobby
                  << " as a hobby and it's weight equals " << weight << std::endl;
    else
        std::cout << "Cow is noname\n";
}
