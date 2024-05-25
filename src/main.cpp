#include <iostream>
#include <cmath>
#include "../headers/hgexcept.h"

double hmean(double a, double b) throw (hmeanxcept&);
double gmean(double a, double b) throw (gmeanxcept&);

int main()
{
    double x, y, z;
    std::cout << "Enter two numbers: ";
    while (std::cin >> x >> y)
    {
        try {
        z = hmean(x , y);
        std::cout << "Harmonic mean of " << x << " and "
                  << y << " is " << z << std::endl;
        z = gmean(x , y);
        std::cout << "Geometric mean of " << x << " and "
                  << y << " is " << z << std::endl;
        }

        catch (hmeanxcept& hm)
        {
            std::cout << hm.what();
        }

        catch (gmeanxcept& gm)
        {
            std::cout << gm.what();
            break;
        }
         std::cout << "Please enter new values:\n";
    }
    std::cout << "Bye!\n";
    return 0;
}

double hmean(double a, double b) throw (hmeanxcept&)
{
    if(a == -b)
        throw hmeanxcept();
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw (gmeanxcept&)
{
    if(a < 0 || b < 0)
        throw gmeanxcept();
    return sqrt(a * b);
}
