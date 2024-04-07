#ifndef BADDUDE_H
#define BADDUDE_H

#include "gunslinger.h"
#include "pokerplayer.h"

class BadDude : public Gunslinger, public PokerPlayer
{
public:
    BadDude() : Person(), Gunslinger(), PokerPlayer(){}
    BadDude(Strings nm, Strings snm, int ns = 0) : Person(nm, snm), Gunslinger(nm, snm, ns), PokerPlayer(nm, snm){}
    ~BadDude();
    double Gdraw();
    Card& Cdraw();
    void Show() override;
    void Set() override;
private:

};

#endif // BADDUDE_H
