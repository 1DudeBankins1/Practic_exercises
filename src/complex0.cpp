#include "../headers/complex0.h"
#include <iostream>

Complex0::Complex0()
{
    real = 0;
    imagine = 0;
}

Complex0::Complex0(double r, double i)
{
    real = r;
    imagine = i;
}

Complex0::~Complex0()
{

}

void Complex0::set(double r, double i)
{
    real = r;
    imagine = i;
}

Complex0 Complex0::operator+(const Complex0& comp) const
{
    return Complex0(real + comp.real, imagine + comp.imagine);
}

Complex0 Complex0::operator-(const Complex0& comp) const
{
    return Complex0(real - comp.real, imagine - comp.imagine);
}

Complex0 Complex0::operator*(const Complex0& comp) const
{
    return Complex0(real * comp.real, imagine * comp.imagine);
}

Complex0 Complex0::operator*(const double n) const
{
    return Complex0(real * n, imagine * n);
}

Complex0 Complex0::operator~() const
{
    return Complex0(real, -imagine);
}

Complex0 operator*(const double n, const Complex0& comp)
{
    return comp * n;
}

std::ostream& operator<<(std::ostream& os, const Complex0& comp)
{
    os << "(" << comp.real << "," << comp.imagine << "i)\n";
    return os;
}

std::istream& operator>>(std::istream& is, Complex0& comp)
{
    std::cout << "real: ";
    is >> comp.real;
    std::cin.get();
    std::cout << "imaginary: ";
    is >> comp.imagine;
    std::cin.get();
    return is;
}
