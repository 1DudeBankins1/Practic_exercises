#include "../headers/arraydb.h"

ArrayDb::ArrayDb() : size(1)
{
    arr = new double[size];
}

ArrayDb::ArrayDb(unsigned int n, double val) : size(n)
{
    arr = new double[size];
    for (int i = 0; i < size; ++i)
        arr[i] = val;
}

ArrayDb::ArrayDb(const double* pn, unsigned int n) : size(n)
{
    arr = new double[size];
    for (int i = 0; i < size; ++i)
        arr[i] = pn[i];
}

ArrayDb::ArrayDb(const ArrayDb& adb) : size(adb.size)
{
    arr = new double[size];
    for (int i = 0; i < size; ++i)
        arr[i] = adb.arr[i];
}

ArrayDb::~ArrayDb()
{
    delete[] arr;
}

double ArrayDb::Average() const
{
    double sum = 0;
    for (int i = 0; i < size; ++i)
        sum += arr[i];
    return (sum/size);
}

double& ArrayDb::operator[](int i)
{
    if (i < 0 || i >= size)
    {
        std::cerr << "Invalid iterator\n";
        exit(1);
    }
    return arr[i];
}

const double& ArrayDb::operator[](int i) const
{
    if (i < 0 || i >= size)
    {
        std::cerr << "Invalid iterator\n";
        exit(1);
    }
    return arr[i];
}

ArrayDb& ArrayDb::operator=(const ArrayDb& adb)
{
    if(this == &adb)
        return *this;
    size = adb.size;
    delete[] arr;
    arr = new double[size];
    for (int i = 0; i < size; ++i)
        arr[i] = adb.arr[i];
    return *this;
}

std::ostream& operator<<(std::ostream& os, const ArrayDb& adb)
{
    for (int i = 0; i < adb.size; ++i)
    {
        os << adb.arr[i] << " ";
        if (i % 5 == 4)
            os << '\n';
    }
    if (adb.size % 5 != 0)
        os << '\n';
    return os;
}
