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
void cust_show(std::ostream& os, const customer& cust);

typedef customer Item;

class Stack
{
private:
    enum {MAX = 10};
    Item* pitems;
    int top;
    int size;

public:
    Stack(int n = 10);
    Stack(const Stack& st);
    ~Stack();
    bool isEmpty() const;
    bool isFull() const;
    bool push(const Item& it);
    bool pop(Item& it);
    Stack& operator=(const Stack& st);
    friend std::ostream& operator<<(std::ostream& os, const Stack& st);
};

#endif // STACK_H
