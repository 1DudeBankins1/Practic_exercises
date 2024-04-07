#ifndef GUNSLINGER_H
#define GUNSLINGER_H

#include "person.h"

class Gunslinger : virtual public Person
{
private:
    int num_shot;
    double tim;
public:
    Gunslinger() : Person(), num_shot(0), tim(0.0) {}
    Gunslinger(Strings nm, Strings snm, int ns = 0, double t = 0.0) : Person(nm, snm), num_shot(ns), tim(t) {}
    Gunslinger(const Gunslinger& gs) : Person(gs), num_shot(gs.num_shot), tim(gs.tim) {}
    ~Gunslinger();
    double Draw();
    void Show() override;
    virtual void Set() override;
    void Data();
};

#endif // GUNSLINGER_H
