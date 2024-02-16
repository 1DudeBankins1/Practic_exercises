#include <iostream>
#include <cstdlib>
#include "../headers/stack.h"

const int CUST_NUM = 5;

int main(int argc, char* argv[])
{
    Item custs[CUST_NUM];

    for (int i = 0; i < CUST_NUM; i++)
        custs[i] = create_cust();

    Stack st1(CUST_NUM);
    for (int i = 0; i < CUST_NUM; i++)
        st1.push(custs[i]);
    st1.push(custs[0]);
    std::cout << st1;

    Stack st2(st1);
    std::cout << st2;
    Item popped;
    for (int i = 0; i < 2; i++){
        st2.pop(popped);
        std::cout << popped.fullname << " is popped\n";
    }
    std::cout << st2;

    Stack st3;
    st3.push(create_cust());
    std::cout << st3;
    st3 = st2;
    std::cout << st3;

    return 0;
}
