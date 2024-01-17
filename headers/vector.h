#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
private:
    double x;
    double y;
    double mag; //length of vector
    double ang; //direction of vector
    char mode; //r - rectangle, p - polar

    void set_mag();
    void set_ang();
    void set_x();
    void set_y();

public:
    Vector();
    Vector(double n1, double n2, char form = 'r');
    void set(double n1, double n2, char form = 'r');
    ~Vector();

    double xval() const {return x;}
    double yval() const {return y;}
    double magval() const {return mag;}
    double angval() const {return ang;}
    void polar_mode();
    void rect_mode();

    Vector operator+(const Vector& v) const;
    Vector operator-(const Vector& v) const;
    Vector operator-() const;
    Vector operator*(double n) const;

    friend Vector operator*(double n, const Vector &v);
    friend std::ostream & operator<<(std::ostream & os, const Vector& v);
};

#endif // VECTOR_H
