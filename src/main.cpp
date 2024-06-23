#include <iostream>
#include <cstring>

int main(int argc, char* argv[])
{
    std::cout << "Enter the string:\n";
    char str[40];

    std::cin.get(str, 40, '#');

    std::cout << "The string has " << strlen(str) << " symbols until #\n";

    std::cout << "And " << (char)std::cin.get() << " left in stream\n";

    while (std::cin.get() != '\n')
        continue;

    return 0;
}
