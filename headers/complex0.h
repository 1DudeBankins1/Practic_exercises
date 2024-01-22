#ifndef COMPLEX0_H
#define COMPLEX0_H

#include <iostream>

class Complex0
{
private:
    double real;
    double imagine;


public:
    Complex0();
    Complex0(double r, double i = 0);
    ~Complex0();

    void set(double r, double i = 0);

    Complex0 operator+(const Complex0& comp) const;
    Complex0 operator-(const Complex0& comp) const;
    Complex0 operator*(const Complex0& comp) const;
    Complex0 operator*(const double n) const;
    Complex0 operator~() const;

    friend Complex0 operator*(const double n, const Complex0& comp);
    friend std::ostream& operator<<(std::ostream& os, const Complex0& comp);
    friend std::istream& operator>>(std::istream& is, Complex0& comp);
};

#endif // COMPLEX0_H
