#include "func.h"

int setgolf(golf& g)
{
    char n[LEN];
    int h;
    std::cout << "Enter golf name:";
    std::cin.getline(n, LEN);
    if (!*n)
        return 0;
    strncpy(g.fullname, n, strlen(n));
    std::cout << "Enter golf handicap:";
    std::cin >> h;
    std::cin.get();
    g.handicap = h;
    return 1;
}

void setgolf(golf& g, const char* name, int hc)
{
    strncpy(g.fullname, name, strlen(name));
    g.handicap = hc;
}

void handicap(golf& g, int hc)
{
    g.handicap = hc;
}

void showgolf(const golf& g)
{
    std::cout << "Handicap of " << g.fullname << " = " << g.handicap << std::endl;
}
