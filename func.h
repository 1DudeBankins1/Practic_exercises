#ifndef FUNC_H
#define FUNC_H

#include <cstring>

template <typename T>
T maxn(T arr[], int n)
{

    T max = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

template <>
char* maxn(char* arr[], int n)
{

    int len = 0;
    int num = 0;

    for (int i = 0; i < n; i++)
    {
        if(strlen(arr[i]) > len){
            len = strlen(arr[i]);
            num = i;
        }
    }

    return arr[num];
}

#endif // FUNC_H
