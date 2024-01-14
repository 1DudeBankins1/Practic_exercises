#include <iostream>
#include <ctime>
#include <cstdlib>
#include "vector.h"


int main(int argc, char* argv[])
{
    double st, target, direction;
    unsigned int num = 0, max, min, average, attempts, count = 0;
    Vector step;
    Vector result;
    srand(time(NULL));

    std::cout << "Enter the target or 'q' to quit: ";
    while (std::cin >> target)
    {
        std::cout << "Enter the step: ";
        std::cin >> st;

        std::cout << "Enter the amount of attempts: ";
        std::cin >> attempts;
        while (count < attempts)
        {
            while(result.magval() < target){
                direction = rand() % 360;
                step.set(st, direction, 'p');
                result = result + step;
                num++;
            }
            std::cout << "Number" << count+1 << std::endl;
            result.polar_mode();
            std::cout << result;
            result.rect_mode();
            std::cout << " or " << result;
            std::cout << "Amount of steps:" << num << std::endl;
            if (!count){
                max = min = num;
            }
            else{
                if (max < num)
                    max = num;
                if (min > num)
                    min = num;
            }
            average+=num;
            result.set(0,0);
            num = 0;
            count++;
        }
        std::cout << "\nMaximum steps = " << max << std::endl;
        std::cout << "Minimum steps = " << min << std::endl;
        std::cout << "Average steps = " << average/attempts << std::endl;
        count = 0;
        average = 0;
        std::cout << "Enter the target or 'q' to quit: ";
    }

    return 0;
}
