#include <iostream>
#include <cstdlib>
#include "../headers/cow.h"

int main(int argc, char* argv[])
{
    Cow cow_1;
    std::cout << "cow №1\n";
    cow_1.ShowCow();
    Cow cow_2("Murka", "Eating grass", 455.7);
    Cow cow_3("Milf", "Milking", 501.2);
    Cow cow_4(cow_2);
    cow_1 = cow_3;

    std::cout << "cow №1 = cow №3\n";
    cow_1.ShowCow();
    std::cout << "cow №2\n";
    cow_2.ShowCow();
    std::cout << "cow №3\n";
    cow_3.ShowCow();
    std::cout << "cow №4 = cow №2\n";
    cow_4.ShowCow();

    return 0;
}
