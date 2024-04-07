#include <iostream>
#include <cstring>
#include "../headers/baddude.h"
#include "../headers/queueTp.h"

const int SIZE = 5;

int main()
{
    Queue<Person*> dmitry_band;
    int ct;
    for(ct = 0; ct < SIZE; ++ct)
    {
        char choice;
        std::cout << "Enter the guy category: \n g: gunslinger p: Poker player b: Bad dude q: quit\n";
        std::cin >> choice;
        while (strchr("gpbq", choice) == NULL)
        {
             std::cout << "Please enter g, p, b or q: ";
             std::cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice){
            case 'g': {
                dmitry_band.enQueue(new Gunslinger);
                break;
            }
            case 'p': {
                dmitry_band.enQueue(new PokerPlayer);
                break;
            }
            case 'b': {
                dmitry_band.enQueue(new BadDude);
                break;
            }
        }
        std::cin.get();
        dmitry_band.current()->Set();
    }

    std::cout << "\nHere's your staff:\n";
    for(int i = 0; i < ct; ++i)
    {
        Person* tempw;
        dmitry_band.deQueue(tempw);
        tempw->Show();
    }
    if (dmitry_band.isEmpty())
        std::cout << "Your staff completed!\n";

    return 0;
}
