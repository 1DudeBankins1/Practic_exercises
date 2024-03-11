#ifndef PORT_H
#define PORT_H

#include <iostream>

class Port
{
private:
    char* brand;
    char style[20];
    int bottles;
public:
    Port(const char *br = "none", const char *st = "none", int b = 0);
    Port(const Port& po);
    virtual ~Port();
    Port& operator=(const Port& po);
    Port& operator+=(int b);
    Port& operator-=(int b);
    int BottleCount() const;
    virtual void Show() const;
    friend std::ostream& operator<<(std::ostream& os, const Port& po);
};

#endif // PORT_H
