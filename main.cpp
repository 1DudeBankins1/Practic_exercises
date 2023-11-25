#include "func.h"
#include "Bank_bill.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    Bank_Bill mine("Dmitry", "88005553555", 20000.0);
    Bank_Bill maxs("Maxim", "99336342177");
    Bank_Bill bomj;

    mine.show();
    maxs.show();
    bomj.show();

    mine.invest(35000.0);
    maxs.invest(350.0);
    maxs.withdraw(200.5);
    bomj.invest(1000);

    mine.show();
    maxs.show();
    bomj.show();

    return 0;
}
