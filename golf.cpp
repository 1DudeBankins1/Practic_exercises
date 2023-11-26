#include "golf.h"

Golf::Golf()
{
    char n[LEN];
    int h;
    std::cout << "Enter golf name:";
    std::cin.getline(n, LEN);
    if (!(*n))
        strncpy(fullname, "Noname", strlen("Noname"));
    else
        strncpy(fullname, n, strlen(n));
    std::cout << "Enter golf handicap:";
    std::cin >> h;
    std::cin.get();
    handicap = h;
}

Golf::Golf(const char *name, int hc)
{
    strncpy(fullname, name, strlen(name));
    handicap = hc;
}

Golf::~Golf()
{

}

void Golf::set_handicap(int hc)
{
    handicap = hc;
}

void Golf::showgolf()
{
    std::cout << "Handicap of " << fullname << " = " << handicap << std::endl;
}
