#include "../headers/baddude.h"

BadDude::~BadDude()
{

}

double BadDude::Gdraw()
{
    return Gunslinger::Draw();
}

Card& BadDude::Cdraw()
{
    return PokerPlayer::Draw();
}

void BadDude::Show()
{
    Gunslinger::Show();
    PokerPlayer::Data();
}

void BadDude::Set()
{
    Gunslinger::Set();

}
