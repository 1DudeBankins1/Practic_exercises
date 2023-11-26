#ifndef GOLF_H
#define GOLF_H
#include<iostream>
#include<cstring>

const int LEN = 40;

class Golf
{
public:
    Golf();
    Golf(const char* name, int hc);
    ~Golf();
    void set_handicap(int hc);
    void showgolf();

private:
    char fullname[LEN];
    int handicap;
};

#endif // GOLF_H
