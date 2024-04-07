#ifndef CARD_H
#define CARD_H

#include"strings.h"
#include <iostream>

const Strings SUIT[]= {"hearts", "diamonds", "cross", "spades"};
const Strings WEIGHT[]= {"six", "seven", "eight", "nine", "ten", "knave", "queen", "king", "joker"};

class Card
{
public:
    enum suits : int {hearts = 0, diamonds, cross, spades};
    enum weights : int {six = 0, seven, eight, nine, ten, knave, queen, king, joker};
    Card(suits s = hearts, weights w = six) : suit(s), weight(w){}
    Card(const Card& c) : suit(c.suit), weight(c.weight){}
    ~Card(){}
    friend std::ostream& operator<<(std::ostream& os, const Card& ca)
    {
        os << WEIGHT[ca.weight] << " of " << SUIT[ca.suit] << "\n";
        return os;
    }
private:
    suits suit;
    weights weight;
};
#endif // CARD_H
