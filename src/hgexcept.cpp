#include "../headers/hgexcept.h"

hmeanxcept::hmeanxcept() : std::exception()
{

}

const char* hmeanxcept::what()
{
    return "Hmean exception\n"
           "a = -b\n";
}

gmeanxcept::gmeanxcept() : std::exception()
{

}

const char* gmeanxcept::what()
{
    return "Gmean exception\n"
           "a < 0 or b < 0\n";
}
