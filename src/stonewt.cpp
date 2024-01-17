#include <iostream>
#include <cmath>
#include "../headers/stonewt.h"

const double Rad2deg = 57.2957795130823;

Stonewt::Stonewt()
{
    pounds = stone = pds_left = 0;
    mode = 'p';
}

Stonewt::Stonewt(double lbs, char form)
{
    pounds = lbs;
    stone = (int) (lbs / Lbs_per_stn);
    pds_left = ((int)lbs % Lbs_per_stn) + (lbs - (int)lbs);
    mode = form;
}

Stonewt::Stonewt(int stn, double lbs, char form)
{
    pounds = stn * Lbs_per_stn + lbs;
    stone = stn;
    pds_left = lbs;
    mode = form;
}

Stonewt::~Stonewt()
{

}

void Stonewt::set(double lbs, char form)
{
    pounds = lbs;
    stone = (int) (lbs / Lbs_per_stn);
    pds_left = ((int)lbs % Lbs_per_stn) + (lbs - (int)lbs);
    mode = form;
}

void Stonewt::set(int stn, double lbs, char form)
{
    pounds = stn * Lbs_per_stn + lbs;
    stone = stn;
    pds_left = lbs;
    mode = form;
}

void Stonewt::pound_mode()
{
    mode = 'p';
}

void Stonewt::stone_mode()
{
    mode = 's';
}

Stonewt Stonewt::operator+(const Stonewt &v) const
{
    return Stonewt(pounds + v.pounds);
}

Stonewt Stonewt::operator-(const Stonewt &v) const
{
    return Stonewt(pounds - v.pounds);
}

Stonewt Stonewt::operator*(double n) const
{
    return Stonewt(pounds * n);
}

Stonewt operator*(double n, const Stonewt &v)
{
    return (v * n);
}

std::ostream & operator<<(std::ostream &os, const Stonewt& v)
{
    if (v.mode == 'p')
    {
        os << "pounds = " << v.pounds << "\n";
    }
    else if (v.mode == 's')
    {
        os << "stone = " << v.stone << " and " << v.pds_left << " pounds\n";
    }
    else
        os << "Stonewt is invalid\n";
    return os;
}
