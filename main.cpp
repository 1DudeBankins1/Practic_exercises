#include "main.h"

int main()
{
    int n = 0;

    std::cout << "Enter the number of the handicaps:";
    std::cin >> n;
    std::cin.get();
    golf* g = new golf[n];

    int i = 0;
    bool res;
    do{
        res = setgolf(g[i]);
        if (res)
            i++;
    }
    while(res && (i<n));

    n = 0;
    while (n < i){
        showgolf(g[n]);
        n++;
    }

    if (i > 0){
        setgolf(g[0], "Dimka Voron", 26);
        showgolf(g[0]);
        handicap(g[0], 666);
        showgolf(g[0]);
    }

    delete[] g;
    return 0;
}
