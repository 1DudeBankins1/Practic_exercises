#include <iostream>
#include "../headers/classic.h"

void bravo(const Cd& disk);

int main(int argc, char* argv[])
{
    Cd c1((char*)"Beatles", (char*)"Capitol", 14, 35.5);
    Classic c2 = Classic((char*)"Piano Sonata in B flat, Fantasia in C",
                         (char*)"Alfred Brendel", (char*)"Philips", 2, 57.17);
    Cd *pcd = &c1;

    std::cout << "Using object directly:\n";
    c1.report();
    c2.report();

    std::cout << "\nUsing type cd* pointer to objects:\n";
    pcd->report();
    pcd = &c2;
    pcd->report();

    std::cout << "\nCalling a function with a Cd reference argument:\n";
    bravo(c1);
    bravo(c2);

    std::cout << "\nTesting assigments:\n";
    Classic copy = c2;
    copy.report();

    return 0;
}

void bravo(const Cd& disk)
{
    disk.report();
}
