#include "func.h"
#include <iostream>

using namespace std;

int main()
{
    int n_int, n_doub, n_str;

    std::cout << "Enter the size of int array:";
    std:: cin >> n_int;
    int* arr_int = new int[n_int];

    std::cout << "Enter the size of double array:";
    std::cin >> n_doub;
    double* arr_doub = new double[n_doub];

    std::cout << "Enter the size of string array:";
    std:: cin >> n_str;
    char** arr_str = new char*[n_str];
    for (int i = 0; i < n_str; i++)
        arr_str[i] = new char[40];

    std::cin.get();
    for (int i = 0; i < n_str; i++){
        std::cout << "Enter " << i+1 << " string:";
        std::cin.getline(arr_str[i], 40);
    }

    std::cout << "Enter the " << n_int << " numbers of int array:";
    for (int i = 0; i < n_int; i++)
        std::cin >> arr_int[i];

    std::cout << "Enter the " << n_doub << " numbers of double array:";
    for (int i = 0; i < n_doub; i++)
        std::cin >> arr_doub[i];

    std::cout << "The max of int array:\n" << maxn<int>(arr_int, n_int) << "\n";
    std::cout << "The max of double array:\n" << maxn(arr_doub, n_doub) << "\n";
    std::cout << "The max of string array:\n" << maxn<char*>(arr_str, n_str) << std::endl;

    delete[] arr_int;
    delete[] arr_doub;

    for (int i = 0; i < n_str; i++)
        delete[] arr_str[i];
    delete[] arr_str;

    return 0;
}
