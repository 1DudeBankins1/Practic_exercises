#include "../headers/vintageport.h"
#include <cstring>

VintagePort::VintagePort() : Port()
{
    nickname = new char[5];
    std::strncpy(nickname, "none", 4);
    nickname[4] = '\0';
    year = -1;
}

VintagePort::VintagePort(const char *br, int b, const char *nn, int y) : Port(br, "none", b)
{
    nickname = new char[std::strlen(nn) + 1];
    std::strncpy(nickname, nn, std::strlen(nn));
    nickname[std::strlen(nn)] = '\0';
    year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp)
{
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strncpy(nickname, vp.nickname, std::strlen(vp.nickname));
    nickname[std::strlen(vp.nickname)] = '\0';
    year = vp.year;
}

VintagePort::~VintagePort()
{
    delete[] nickname;
}

VintagePort& VintagePort::operator=(const VintagePort& vp)
{
    if (this == &vp)
        return *this;
    Port::operator=(vp);
    delete[] nickname;
    nickname = new char[std::strlen(vp.nickname) + 1];
    std::strncpy(nickname, vp.nickname, std::strlen(vp.nickname));
    nickname[std::strlen(vp.nickname)] = '\0';
    year = vp.year;
    return *this;
}

void VintagePort::Show() const
{
    Port::Show();
    std::cout << "Nickname: " << nickname << "\nYear: " << year << std::endl;
}

std::ostream& operator<<(std::ostream& os, const VintagePort& po)
{
    os << (Port&)po << po.nickname << ", " << po.year << std::endl;
    return os;
}
