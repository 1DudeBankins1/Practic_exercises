#include <iostream>
#include <cstring>
#include "../headers/tv.h"

const int SIZE = 5;

int main()
{
    Tv Samsung;
    std::cout << "Initial settings for Samsung:\n";
    Samsung.settings();
    Samsung.onoff();
    Samsung.chanup();
    std::cout << "\nAdjusted settings for Samsung:\n";
    Samsung.settings();

    Remote Philips;
    Philips.set_chan(Samsung, 9);
    Philips.volup(Samsung);
    Philips.volup(Samsung);
    Philips.get_control();
    std::cout << "\nSettings after using remote:\n";
    Samsung.settings();

    Tv LG(Tv::On);
    LG.set_mode();
    Philips.set_chan(LG, 69);
    std::cout << "\nLG settings:\n";
    LG.settings();

    LG.set_control(Philips);
    Philips.get_control();

    return 0;
}
