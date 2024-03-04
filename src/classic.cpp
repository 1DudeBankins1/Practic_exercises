#include "../headers/classic.h"
#include<cstring>
#include<iostream>

Classic::Classic(char* mt, char* s1, char* s2, int n, double x) : Cd(s1, s2, n, x)
{
    std::strcpy(main_task, mt);
}

Classic::Classic(const Classic& cl) : Cd(cl)
{
    std::strcpy(main_task, cl.main_task);
}

Classic::Classic()
{
    Cd();
    std::strcpy(main_task, "None");
}

Classic::~Classic()
{

}

void Classic::report() const
{
    Cd::report();
    std::cout << "First main task is: " << main_task << std::endl;
}

Classic& Classic::operator=(const Classic &cl)
{
    if (&cl == this)
        return *this;
    Cd::operator=(cl);
    std::strcpy(main_task, cl.main_task);
    return *this;
}
