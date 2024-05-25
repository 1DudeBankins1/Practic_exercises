#pragma once
#include <exception>
#include <string>

class hmeanxcept : public std::exception
{
public:
    hmeanxcept();
    const char* what();
};

class gmeanxcept : public std::exception
{
public:
    gmeanxcept();
    const char* what();
};
