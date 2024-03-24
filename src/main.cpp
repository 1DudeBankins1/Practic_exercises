#include <iostream>
#include <cstring>
#include "../headers/queueTp.h"
#include "../headers/workermi.h"

const int SIZE = 5;

int main()
{
    Queue<Worker*> dmitrys;
    int ct;
    for(ct = 0; ct < SIZE; ++ct)
    {
        char choice;
        std::cout << "Enter the employee category: \n w: waiter s: singer t: singing waiter q: quit\n";
        std::cin >> choice;
        while (strchr("wstq", choice) == NULL)
        {
             std::cout << "Please enter w, s, t or q: ";
             std::cin >> choice;
        }
        if (choice == 'q')
            break;
        switch (choice){
            case 'w': {
                dmitrys.enQueue(new Waiter);
                break;
            }
            case 's': {
                dmitrys.enQueue(new Singer);
                break;
            }
            case 't': {
                dmitrys.enQueue(new SingingWaiter);
                break;
            }
        }
        std::cin.get();
        dmitrys.current()->set();
    }

    std::cout << "\nHere's your staff:\n";
    for(int i = 0; i < ct; ++i)
    {
        Worker* tempw;
        dmitrys.deQueue(tempw);
        tempw->show();
    }
    if (dmitrys.isEmpty())
        std::cout << "Your staff completed!\n";

    return 0;
}
