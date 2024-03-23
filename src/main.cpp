#include <iostream>
#include "../headers/wine.h"

int main()
{
    ArrayDb buf[2];
    buf[0] = ArrayDb(2, 56.6);
    buf[1] = ArrayDb(4, 23.5);

    std::cout << buf[0];
    std::cout << buf[1];

    int wine_num;
    std::cout << "Enter the number of wines: ";
    std::cin >> wine_num;
    while (std::cin.get() != '\n') continue;

    Wine* wines = new Wine[wine_num];

    for (int i = 0; i < wine_num; ++i){
        std::cin >> wines[i];
    }

    for (int i = 0; i < wine_num; ++i){
        std::cout << wines[i];
    }

    delete[] wines;
    return 0;
}
