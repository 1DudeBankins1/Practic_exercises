#include "../headers/tv.h"
#include <iostream>

bool Tv::volup()
{
    if (volume < MaxVal)
    {
        volume++;
        return true;
    }
    else
        return false;
}

bool Tv::voldown()
{
    if (volume > MinVal)
    {
        volume--;
        return true;
    }
    else
        return false;
}

void Tv::chanup()
{
    if (channel < maxchannel)
        channel++;
    else
        channel = 1;
}

void Tv::chandown()
{
    if (channel > 1)
        channel--;
    else
        channel = maxchannel;
}

void Tv::settings() const
{
    std::cout << "TV is " << (state == Off ? "Off" : "On") << '\n';
    if (state == On)
    {
        std::cout << "Volume setting = " << volume << '\n';
        std::cout << "Channel setting = " << channel << '\n';
        std::cout << "Mode = " << (mode == Antenna? "antenna" : "cable") << '\n';
        std::cout << "Input = " << (input == TV? "TV" : "VCR") << '\n';
    }
}

bool Tv::set_control(Remote &r)
{
    if (state == On){
        r.control = (r.control == Remote::Manual ? Remote::Interact : Remote::Manual);
        return true;
    }
    return false;
}

void Remote::get_control() const
{
    std::cout << "Control mode is " << (control == Manual ? "Manual" : "Interact") << '\n';
}
