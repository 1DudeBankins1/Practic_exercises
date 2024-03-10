#include "../headers/classic.h"
#include<cstring>
#include<iostream>

Classic::Classic(char* mt, char* s1, char* s2, int n, double x) : Cd(s1, s2, n, x)
{
    main_task = new char[std::strlen(mt)+1];
    std::strcpy(main_task, mt);
}

Classic::Classic(const Classic& cl) : Cd(cl)
{
    main_task = new char[5];
    std::strcpy(main_task, "Play");
}

Classic::Classic()
{
    Cd();
    main_task = new char[5];
    std::strcpy(main_task, "Play");
}

Classic::~Classic()
{
    delete[] main_task;
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
    delete[] main_task;
    main_task = new char[std::strlen(cl.main_task)+1];
    std::strcpy(main_task, cl.main_task);
    return *this;
}
