#include "func.h"

template <typename T>
T max5(T* arr)
{
    T max = arr[0];
    for (int i = 0; i < 5; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}
