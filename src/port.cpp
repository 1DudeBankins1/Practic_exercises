#include "../headers/port.h"
#include <cstring>

Port::Port(const char *br, const char *st, int b)
{
    brand = new char[std::strlen(br) + 1];
    std::strncpy(brand, br, std::strlen(br));
    brand[std::strlen(br)] = '\0';
    std::strncpy(style, st, std::strlen(st));
    bottles = b;
}

Port::Port(const Port& po)
{
    brand = new char[std::strlen(po.brand) + 1];
    std::strncpy(brand, po.brand, std::strlen(po.brand));
    brand[std::strlen(po.brand)] = '\0';
    std::strncpy(style, po.style, std::strlen(po.style));
    bottles = po.bottles;
}

Port::~Port()
{
    delete[] brand;
}

Port& Port::operator=(const Port& po)
{
    if (this == &po)
        return *this;
    delete[] brand;
    brand = new char[std::strlen(po.brand) + 1];
    std::strncpy(brand, po.brand, std::strlen(po.brand));
    brand[std::strlen(po.brand)] = '\0';
    std::strncpy(style, po.style, std::strlen(po.style));
    bottles = po.bottles;
    return *this;
}

Port& Port::operator+=(int b)
{
    bottles += b;
    return *this;
}

Port& Port::operator-=(int b)
{
    if(bottles >= b)
        bottles -= b;
    else
        std::cout << "Too few bottles to retrieve!\n";
    return *this;
}

int Port::BottleCount() const
{
    return bottles;
}

void Port::Show() const
{
    std::cout << "Brand: " << brand << std::endl;
    std::cout << "Kind: " << style << std::endl;
    std::cout << "Bottles: " << bottles << std::endl;
}

std::ostream& operator<<(std::ostream& os, const Port& po)
{
    os << po.brand << ", " << po.style << ", " << po.bottles << std::endl;
    return os;
}
