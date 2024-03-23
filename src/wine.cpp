#include "../headers/wine.h"

Wine::Wine()
{
    name = "Unknown";
    years = 1;
    num = new ArrayDb[years];
}

Wine::Wine(Strings nm, ArrayDb* arr, int y) : name(nm), years(y)
{
    num = new ArrayDb[years];
    for (int i = 0; i < years; ++i)
        num[i] = arr[i];
}

Wine::~Wine()
{
    delete[] num;
}

Wine::Wine(const Wine& wn) : name(wn.name), years(wn.years)
{
    num = new ArrayDb[years];
    for (int i = 0; i < years; ++i)
        num[i] = wn.num[i];
}

Wine& Wine::operator=(const Wine& wn)
{
    if (this == &wn)
        return *this;
    name = wn.name;
    years = wn.years;
    delete[] num;
    num = new ArrayDb[years];
    for (int i = 0; i < years; ++i)
        num[i] = wn.num[i];
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Wine& wn)
{
    os << "Wine \"" << wn.name << "\" has " << wn.years << " years:\n";
    for (int i = 0; i < wn.years; ++i){
        os << wn.num[i] << " - " << wn[i].ArSize() << " bottles\n";
    }
    return os;
}

ArrayDb& Wine::operator[](int i)
{
    if (i < 0 || i >= years)
    {
        std::cerr << "Invalid iterator\n";
        exit(1);
    }
    return num[i];
}

const ArrayDb& Wine::operator[](int i) const
{
    if (i < 0 || i >= years)
    {
        std::cerr << "Invalid iterator\n";
        exit(1);
    }
    return num[i];
}

std::istream& operator>>(std::istream& is, Wine& wn)
{
    unsigned int n = 0;
    double val = 0.0;

    std::cout << "Enter name of wine: ";
    is >> wn.name;
    std::cout << "Enter count of years: ";
    is >> wn.years;
    while (is.get() != '\n') continue;
    ArrayDb* temp = new ArrayDb[wn.years];
    for (int i = 0; i < wn.years; ++i){
        std::cout << "Enter " << i+1 << " year: ";
        is >> val;
        while (is.get() != '\n') continue;
        std::cout << "Enter number of bottles in this year: ";
        is >> n;
        while (is.get() != '\n') continue;
        temp[i] = ArrayDb(n, val);
    }
    wn.num = temp;
    //delete[] temp;
    return is;
}
