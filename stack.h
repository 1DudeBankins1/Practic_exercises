#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <cstring>

const int NAME_SIZE = 35;

struct customer {
    char fullname[NAME_SIZE];
    double payment;
};

customer create_cust();

typedef customer Item;

class Stack
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
    double summ;
    void summ_show()
    {
        std::cout << "Current summ equals " << summ << std::endl;
    }

public:
    Stack();
    bool pushback(const Item& cust);
    bool popback(Item& cust);

};

#endif // STACK_H
