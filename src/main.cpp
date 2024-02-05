#include <iostream>
#include <cstdlib>
#include "../headers/strings.h"

int main(int argc, char* argv[])
{
    Strings s1(" and I am a C++ student.");
    Strings s2 = "Please enter your name: ";
    Strings s3;
    std::cout << s2;
    std::cin >> s3;
    s2 = "My name is " + s3;
    std::cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.stringup();
    std::cout << "The string\n" << s2
              << "\ncontains " << s2.has('A')
              << " 'A' characters in it.\n";
    s1 = "red";
    Strings rgb[3] = {Strings(s1), Strings("green"),
                     Strings("blue")};
    std::cout << "Enter the name of a primary "
                 "color for mixing light: ";
    Strings ans;
    bool success = false;
    while(std::cin >> ans)
    {
        ans.stringlow();
        for (int i = 0; i < 3; i++)
        {
            if (ans == rgb[i])
            {
                std::cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success)
            break;
        else
            std::cout << "Try again!\n";
    }
    std::cout << "Bye\n";
    return 0;
}
