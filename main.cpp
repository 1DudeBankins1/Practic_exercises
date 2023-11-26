#include "golf.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    int n = 0;

        std::cout << "Enter the number of the handicaps:";
        std::cin >> n;
        std::cin.get();
        Golf* g = new Golf[n];
        int i = 0;
        while (i < n){
            g[i].showgolf();
            i++;
        }

        if (i > 0){
            g[0].set_handicap(26);
            g[0].showgolf();
        }

        delete[] g;
        return 0;

    return 0;
}
