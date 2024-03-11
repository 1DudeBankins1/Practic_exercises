#include <iostream>
#include "../headers/vintageport.h"

int main()
{
    Port george("Lihni", "Red Sweet", 10);
    VintagePort fran("Shardone", 5, "Vikky", 1956);
    Port germ(george);
    VintagePort portwein;
    portwein = fran;

    george.Show();
    fran.Show();
    std::cout << germ;
    std::cout << portwein;

    std::cout << std::endl;

    Port* wrio;
    wrio = &germ;
    *wrio += 50;
    wrio->Show();

    wrio = &portwein;
    *wrio -= 3;
    std::cout << *wrio;

    VintagePort* lah;
    lah = &portwein;
    *lah -= 1;
    std::cout << *lah;

    return 0;
}
