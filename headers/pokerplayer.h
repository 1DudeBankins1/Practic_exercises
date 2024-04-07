#ifndef POKERPLAYER_H
#define POKERPLAYER_H

#include "card.h"
#include "person.h"

class PokerPlayer : virtual public Person
{
private:
    Card card;
public:
    PokerPlayer() : Person(){}
    PokerPlayer(Strings nm, Strings snm);
    PokerPlayer(Strings nm, Strings snm, Card& ca);
    PokerPlayer(const PokerPlayer& pp);
    ~PokerPlayer();
    Card& Draw();
    void Show() override;
    virtual void Set() override;
protected:
    void Carded();
    void Data();
};

#endif // POKERPLAYER_H
