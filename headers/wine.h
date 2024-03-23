#ifndef WINE_H
#define WINE_H

#include "strings.h"
#include "arraydb.h"

class Wine
{
private:
    Strings name;
    int years;
    ArrayDb* num;
public:
    Wine();
    Wine(Strings nm, ArrayDb* n, int years);
    ~Wine();
    Wine(const Wine& wn);
    Wine& operator=(const Wine& wn);
    ArrayDb& operator[](int i);
    const ArrayDb& operator[](int i) const;
    friend std::ostream& operator<<(std::ostream& os, const Wine& wn);
    friend std::istream& operator>>(std::istream& is, Wine& wn);
};

#endif // WINE_H
