#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../headers/complex0.h"

const int STNUM = 6;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    Complex0 x(10, 5);
    Complex0 y;
    std::cout << "Enter the complex number, q to quit:\n";

    while (std::cin >> y)
    {
        std::cout << "y = " << y << std::endl;
        std::cout << "complex conjugate is " << ~y << std::endl;
        std::cout << "x + y is " << x + y << std::endl;
        std::cout << "x - y is " << x - y << std::endl;
        std::cout << "x * y is " << x * y << std::endl;
        std::cout << "5 * y is " << 5 * y << std::endl;

        std::cout << "Enter the complex number, q to quit:\n";
    }
    std::cout << "Bye!\n";
    return 0;
}
