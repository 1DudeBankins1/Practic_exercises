#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../headers/stonewt.h"

const int STNUM = 5;

int main(int argc, char* argv[])
{
    Stonewt st[STNUM];

    st[0].set(50, 11.0);
    st[1].set(150.0);
    st[2] = st[0] - st[1];
    st[3] = 5 * st[2];
    st[4] = st[1] + st[2];

    std::cout << "pound mode:\n";
    for (int i = 0; i < STNUM; i++)
        std::cout << st[i];

    std::cout << "\nstone mode:\n";
    for (int i = 0; i < STNUM; i++){
        st[i].stone_mode();
        std::cout << st[i];
    }


    return 0;
}
