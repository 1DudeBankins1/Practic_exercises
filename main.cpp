#include "main.h"

int main()
{
    CandyBar sweet;
    char nme[3][30] = {"Milka",
                       "Konti",
                       "RotFront"};

    Set_str(sweet);
    Print_str(sweet);
    Set_str(sweet, nme[0]);
    Print_str(sweet);
    Set_str(sweet, nme[1], 99.9);
    Print_str(sweet);
    Set_str(sweet, nme[2], 99.9, 450);
    Print_str(sweet);

    return 0;
}
