#include "../headers/person.h"
#include <iostream>

Person::~Person()
{

}

void Person::Show()
{
    std::cout << "Name: " << name << "\n";
    std::cout << "Sirname: " << sirname << "\n";
}

void Person::Name()
{
    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter sirname: ";
    std::cin >> sirname;
}
