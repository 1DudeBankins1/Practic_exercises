#include "../headers/pokerplayer.h"

#include <ctime>

PokerPlayer::PokerPlayer(Strings nm, Strings snm) : Person(nm, snm), card()
{

}

PokerPlayer::~PokerPlayer(){}

PokerPlayer::PokerPlayer(Strings nm, Strings snm, Card& ca) : Person(nm, snm), card(ca){}

PokerPlayer::PokerPlayer(const PokerPlayer& pp) : Person(pp), card(pp.card){}

Card &PokerPlayer::Draw()
{
    srand(time(NULL));
    int s = rand() % 4;
    int w = rand() % 9;
    card = Card(Card::suits(s), Card::weights(w));
    return this->card;
}

void PokerPlayer::Show()
{
    Person::Show();
    std::cout << "The card is " << card << std::endl;
}

void PokerPlayer::Carded()
{
    std::cout << card << std::endl;
}

void PokerPlayer::Set()
{
    Person::Name();
    card = Draw();
}

void PokerPlayer::Data()
{
    card = Draw();
}

