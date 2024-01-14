#include <iostream>
#include <cmath>
#include "vector.h"

const double Rad2deg = 57.2957795130823;

Vector::Vector()
{
    x = 0;
    y = 0;
    set_mag();
    set_ang();
    mode = 'r';
}

Vector::Vector(double n1, double n2, char form)
{
    if (form == 'r')
    {
        mode = form;
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    }
    else if (form == 'p')
    {
        mode = form;
        mag = n1;
        ang = n2 / Rad2deg;
        set_x();
        set_y();
    }
    else
    {
        std::cout << "Incorrect mode entered\nSet vector 0\n";
        x = 0;
        y = 0;
        set_mag();
        set_ang();
        mode = 'r';
    }
}

Vector::~Vector()
{

}

void Vector::set(double n1, double n2, char form)
{
    if (form == 'r')
    {
        mode = form;
        x = n1;
        y = n2;
        set_mag();
        set_ang();
    }
    else if (form == 'p')
    {
        mode = form;
        mag = n1;
        ang = n2;
        set_x();
        set_y();
    }
    else
    {
        std::cout << "Incorrect mode entered\nSet vector 0\n";
        x = 0;
        y = 0;
        set_mag();
        set_ang();
        mode = 'r';
    }
}

void Vector::set_mag()
{
    mag = sqrt(x*x + y*y);
}

void Vector::set_ang()
{
    if (x == 0.0 && y == 0.0)
        ang = 0.0;
    else
        ang = atan2(y, x);
}

void Vector::set_x()
{
    x = mag * cos(ang);
}

void Vector::set_y()
{
    y = mag * sin(ang);
}

void Vector::rect_mode()
{
    mode = 'r';
}

void Vector::polar_mode()
{
    mode = 'p';
}

Vector Vector::operator+(const Vector &v) const
{
    return Vector(x + v.x, y + v.y);
}

Vector Vector::operator-(const Vector &v) const
{
    return Vector(x - v.x, y - v.y);
}

Vector Vector::operator-() const
{
    return Vector(-x, -y);
}

Vector Vector::operator*(double n) const
{
    return Vector(x * n, y * n);
}

Vector operator*(double n, const Vector &v)
{
    return v * n;
}

std::ostream & operator<<(std::ostream & os, const Vector& v)
{
    if (v.mode == 'r')
    {
        os << "x = " << v.x << ", y = " << v.y << "\n";
    }
    else if (v.mode == 'p')
    {
        os << "(m, a) = " << v.mag << ", " << v.ang * Rad2deg << "\n";
    }
    else
        os << "Vector is invalid\n";
    return os;
}
