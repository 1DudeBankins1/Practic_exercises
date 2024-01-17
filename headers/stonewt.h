#ifndef STONEWT_H
#define STONEWT_H

#include <iostream>

class Stonewt
{
private:
    enum {Lbs_per_stn = 14};
    int stone;
    double pds_left;
    double pounds;
    char mode;

public:
    Stonewt();
    Stonewt(double lbs, char form = 'p');
    Stonewt(int stn, double lbs, char form = 'p');
    ~Stonewt();
    void set(double lbs, char form = 'p');
    void set(int stn, double lbs, char form = 'p');

    void pound_mode();
    void stone_mode();

    Stonewt operator+(const Stonewt& st) const;
    Stonewt operator-(const Stonewt& st) const;
    Stonewt operator*(double n) const;
    bool operator<(const Stonewt& st) const;
    bool operator>(const Stonewt& st) const;
    bool operator==(const Stonewt& st) const;
    bool operator<(const double n) const;
    bool operator>(const double n) const;
    bool operator==(const double n) const;

    friend Stonewt operator*(double n, const Stonewt& st);
    friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);
};

#endif // STONEWT_H
