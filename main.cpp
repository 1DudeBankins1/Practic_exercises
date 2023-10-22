#include "main.h"

int main()
{
    int arr_int[5];
    double arr_doub[5];

    std::cout << "Enter the 5 numbers of int array:";
    for (int i = 0; i < 5; i++)
        std::cin >> arr_int[i];

    std::cout << "Enter the 5 numbers of double array:";
    for (int i = 0; i < 5; i++)
        std::cin >> arr_doub[i];

    std::cout << "The max of int array:\n" << max5(arr_int) << "\n";
    std::cout << "The max of double array:\n" << max5(arr_doub) << "\n";

    return 0;
}
