#include "../headers/gunslinger.h"
#include <ctime>

Gunslinger::~Gunslinger()
{

}

double Gunslinger::Draw()
{
    srand(time(NULL));
    return ((rand() % 60) + 1);
}

void Gunslinger::Show()
{
    Person::Show();
    std::cout << "Number of shots: " << num_shot << "\n"
              << "Time for broad runing: " << tim << "\n";
}

void Gunslinger::Set()
{
    Person::Name();
    std::cout << "Enter number of shots: ";
    std::cin >> num_shot;
    tim = Draw();
}

void Gunslinger::Data()
{
    std::cout << "Enter number of shots: ";
    std::cin >> num_shot;
    tim = Draw();
}
