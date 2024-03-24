#include "../headers/workermi.h"
#include <iostream>

Worker::~Worker()
{

}

void Worker::data() const
{
    std::cout << "Name: " << fullname << "\n";
    std::cout << "Employee ID: " << id << "\n";
}

void Worker::get()
{
    std::cin >> fullname;
    std::cout << "Enter worker's ID: ";
    std::cin >> id;
    while (std::cin.get() != '\n') continue;
}

void Waiter::set()
{
     std::cout << "Enter waiter's name: ";
     Worker::get();
     get();
}

void Waiter::show() const
{
    std::cout << "Category: waiter\n";
    Worker::data();
    data();
}

void Waiter::data() const
{
    std::cout << "Panache rating: " << panache << "\n";
}

void Waiter::get()
{
    std::cout << "Enter waiter's panache rating: ";
    std::cin >> panache;
    while (std::cin.get() != '\n') continue;
}

char* Singer::pv[Singer::Vtypes] = {"other", "alto", "contralto", "soprano", "bass", "baritone", "tenor"};

void Singer::set()
{
     std::cout << "Enter singer's name: ";
     Worker::get();
     get();
}

void Singer::show() const
{
    std::cout << "Category: singer\n";
    Worker::data();
    data();
}

void Singer::data() const
{
    std::cout << "Vocal range: " << pv[voice] << "\n";
}

void Singer::get()
{
    std::cout << "Enter singer's vocal range: ";
    int i;
    for (i = 0 ; i < Vtypes; ++i)
    {
        std::cout << i << ": " << pv[i] << "\n";
        if (i % 4 == 3)
            std::cout << '\n';
    }
    if (i % 4 != 0)
        std::cout << '\n';
    std::cin >> voice;
    while (std::cin.get() != '\n') continue;
}


void SingingWaiter::data() const
{
    Singer::data();
    Waiter::data();
}

void SingingWaiter::get()
{
    Singer::get();
    Waiter::get();
}

void SingingWaiter::set()
{
     std::cout << "Enter singing waiter's name: ";
     Worker::get();
     get();
}

void SingingWaiter::show() const
{
    std::cout << "Category: singing waiter\n";
    Worker::data();
    data();
}
