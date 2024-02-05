#include "../headers/strings.h"
#include <iostream>
#include <cstring>
#include <cctype>

#define _CRT_SECURE_NO_WARNINGS

Strings::Strings()
{
    str = new char[1];
    str[0] = '\0';
    len = 4;
}

Strings::Strings(const char* s)
{
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
}

Strings::Strings(const Strings& st)
{
    len = st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
}

Strings::~Strings()
{
    //std::cout << this->str << " is deleting\n";
    delete[] str;
}

Strings& Strings::operator=(const char* s)
{
    delete[] str;
    len = std::strlen(s);
    str = new char[len+1];
    std::strcpy(str, s);
    return *this;
}

Strings operator+(const Strings &st1, const Strings& st2)
{
    char* temp = new char[st1.len + st2.len + 1];
    strcat(strcpy(temp,st1.str), st2.str);
    Strings stt(temp);
    delete[] temp;
    return stt;
}

Strings operator+(const Strings &st, const char* s)
{
    Strings stt(s);
    return st + stt;
}

Strings operator+(const char* s, const Strings& st)
{
    Strings stt(s);
    return stt + st;
}

Strings &Strings::stringlow()
{
    for (int i = 0; i < len; ++i)
    {
        str[i] = std::tolower(str[i]);
    }
    return *this;
}

Strings &Strings::stringup()
{
    for (int i = 0; i < len; ++i)
    {
        str[i] = std::toupper(str[i]);
    }
    return *this;
}

int Strings::has(char c)
{
    int num = 0;
    for (int i = 0; i < len; ++i)
    {
        if (str[i] == c)
            num++;
    }
    return num;
}

Strings& Strings::operator=(const Strings &st)
{
    if (this == &st)
        return *this;
    delete[] str;
    len = st.len;
    str = new char[len+1];
    std::strcpy(str, st.str);
    return *this;
}

bool operator>(const Strings& st1, const Strings& st2)
{
    if (std::strcmp(st1.str, st2.str) > 0)
        return true;
    else
        return false;
}

bool operator<(const Strings& st1, const Strings& st2)
{
    if (std::strcmp(st2.str, st1.str) > 0)
        return true;
    else
        return false;
}

bool operator==(const Strings& st1, const Strings& st2)
{
    if (std::strcmp(st1.str, st2.str) == 0)
        return true;
    else
        return false;
}

std::ostream& operator<<(std::ostream& os, const Strings& st)
{
    os << st.str;
    return os;
}

std::istream& operator>>(std::istream& is, Strings& st)
{
    char temp[80];
    is.get(temp, 80);
    if (is)
        st = temp;
    while (is && is.get() != '\n')
        continue;
    return is;
}
