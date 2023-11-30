#include "move.h"
#include <iostream>

Move::Move(double a, double b)
{
    this->x = a;
    this->y = b;
}

void Move::showmore() const
{
    std::cout << "x = " << this->x << std::endl;
    std::cout << "y = " << this->y << std::endl;
}

Move Move::add(const Move &m) const
{
    double _x, _y;

    _x = m.x;
    _y = this->y + m.y;
    Move new_m(_x, _y);

    return new_m;
}

void Move::reset(double a, double b)
{
    this->x = a;
    this->y = b;
}
