#ifndef FUNC_H
#define FUNC_H

#include <iostream>
#include <cstring>

const int LEN = 40;
struct golf
{
    char fullname[LEN];
    int handicap;
};

int setgolf(golf& g);
void setgolf(golf& g, const char* name, int hc);
void handicap(golf& g, int hc);
void showgolf(const golf& g);

#endif // FUNC_H
