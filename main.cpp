#include "plorg.h"
#include <iostream>

int main(int argc, char* argv[])
{
    Plorg plorg_1("Dimasik", 100);
    plorg_1.show();

    Plorg plorg_2("Max", 60);
    plorg_2.show();

    Plorg plorg_3;
    plorg_3.show();

    plorg_2.set_ci(80);
    plorg_2.show();

    return 0;
}
