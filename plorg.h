#ifndef PLORG_H
#define PLORG_H

const int SIZE = 19;

class Plorg
{
private:
    char name[SIZE];
    int ci;

public:
    Plorg(char nme[SIZE] = "Plorga", int cci = 50);
    void set_ci(int cci);
    void show() const;
};

#endif // PLORG_H
