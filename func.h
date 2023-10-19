#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <cstring>

struct stringly
{
    char* str;
    int ct;
};

void set(stringly& struc, const char* text);
void show(stringly& struc, int n = 1);
void show(char* str, int n = 1);

#endif // FUNC_H
