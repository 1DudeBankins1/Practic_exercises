#include <iostream>
#include <ctime>
#include <cstdlib>
#include "../headers/stonewt.h"

const int STNUM = 6;

int main(int argc, char* argv[])
{
    srand(time(NULL));

    Stonewt st[STNUM] = {
        {(double) (rand()%50)},
        {(int) (rand()%5), (double) (rand()%14)},
        {(int) (rand()%5), (double) (rand()%14)}
    };

    for (int i = 3; i < STNUM; i++)
        st[i].set((double) (rand()%100));

    std::cout << "pound mode:\n";
    for (int i = 0; i < STNUM; i++)
        std::cout << st[i];

    std::cout << "\nstone mode:\n";
    for (int i = 0; i < STNUM; i++){
        st[i].stone_mode();
        std::cout << st[i];
    }

    Stonewt stmin, stmax;
    unsigned int upeleven = 0;
    stmin = stmax = st[0];
    for (int i = 0; i < STNUM; i++){
        if (st[i] > stmax)
            stmax = st[i];
        if (st[i] < stmin)
            stmin = st[i];
        if (st[i] > 11 || st[i] == 11)
            upeleven++;
    }

    std::cout << "\nMax value equals:" << stmax << std::endl;
    std::cout << "Min value equals:" << stmin << std::endl;
    std::cout << "Number of up and equals 11 is " << upeleven << std::endl;

    return 0;
}
