#ifndef CLASSIC_H
#define CLASSIC_H

#include"cd.h"

class Classic : public Cd
{
private:
    char main_task[40];
public:
    Classic(char* mt, char* s1, char* s2, int n, double x);
    Classic(const Classic& c);
    Classic();
    ~Classic();
    void report() const;
    Classic& operator=(const Classic& cl);
};

#endif // CLASSIC_H
