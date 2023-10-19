#include "func.h"

void set(stringly& struc, const char* text)
{
    int len = strlen(text);
    struc.ct = len;
    char* st = new char[len];
    strncpy(st, text, len);
    struc.str = st;

    //delete[] st;
}

void show(stringly& struc, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << struc.str << std::endl;
}

void show(char* str, int n)
{
    for (int i = 0; i < n; i++)
        std::cout << str << std::endl;
}
