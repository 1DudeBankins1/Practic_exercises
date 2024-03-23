#ifndef ARRAYDB_H
#define ARRAYDB_H

#include <iostream>

class ArrayDb
{
private:
    unsigned int size;
    double* arr;
public:
    ArrayDb();
    explicit ArrayDb(unsigned int n, double val = 0.0);
    ArrayDb(const double* pn, unsigned int n);
    ArrayDb(const ArrayDb& adb);
    virtual ~ArrayDb();
    unsigned int ArSize() const { return size;}
    double Average() const;
    
    virtual double& operator[](int i);
    virtual const double& operator[](int i) const;
    ArrayDb& operator=(const ArrayDb& adb);
    friend std::ostream& operator<<(std::ostream& os, const ArrayDb& adb);
};

#endif // ARRAYDB_H
