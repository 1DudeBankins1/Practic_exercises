#ifndef STRINGS_H
#define STRINGS_H

#include <iostream>

class Strings
{
private:
    char* str;
    int len;
public:
    Strings();
    Strings(const char* s);
    Strings(const Strings& st);
    ~Strings();

    int length() const {return len;}
    Strings& operator=(const Strings& st);
    Strings& operator=(const char* s);
    Strings& stringlow();
    Strings& stringup();
    int has(char c);
    friend Strings operator+(const Strings& st1, const Strings& st2);

    friend bool operator>(const Strings& st1, const Strings& st2);
    friend bool operator<(const Strings& st1, const Strings& st2);
    friend bool operator==(const Strings& st1, const Strings& st2);
    friend std::ostream& operator<<(std::ostream& os, const Strings& st);
    friend std::istream& operator>>(std::istream& is, Strings& st);

    friend Strings operator+(const Strings& st, const char* s);
    friend Strings operator+(const char* s, const Strings& st);
};

#endif // STRINGS_H
