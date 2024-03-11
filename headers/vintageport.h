#ifndef VINTAGEPORT_H
#define VINTAGEPORT_H

#include "../headers/port.h"

class VintagePort : public Port
{
private:
    char* nickname;
    int year;
public:
    VintagePort();
    VintagePort(const char *br, int b, const char *nn, int y);
    VintagePort(const VintagePort& vp);
    ~VintagePort();
    VintagePort& operator=(const VintagePort& vp);
    void Show() const;
    friend std::ostream& operator<<(std::ostream& os, const VintagePort& po);
};

#endif // VINTAGEPORT_H
