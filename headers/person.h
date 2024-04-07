#ifndef PERSON_H
#define PERSON_H

#include "strings.h"

class Person
{
private:
    Strings name;
    Strings sirname;
public:
    Person(Strings nm = "Noname", Strings snm = "Unknown") : name(nm), sirname(snm){}
    Person(const Person& psn) : name(psn.name), sirname(psn.sirname) {}
    virtual ~Person();
    virtual void Show();
    void Name();
    virtual void Set() = 0;
};

#endif // PERSON_H
