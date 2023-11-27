#include "stack.h"

Stack::Stack()
{
    top = 0;
    summ = 0.0;
}

bool Stack::pushback(const Item &cust)
{
    if (top < MAX){
        items[top++] = cust;
        return true;
    }
    else{
        std::cout << "Stack is already full" << std::endl;
        return false;
    }
}

bool Stack::popback(Item &cust)
{
    if (top > 0){
        summ += cust.payment;
        summ_show();
        cust = items[--top];
        return true;
    }
    {
        std::cout << "Stack is already empty" << std::endl;
        return false;
    }
}

customer create_cust()
{
    customer cust;
    char nme[NAME_SIZE];
    int paym = 0;

    std::cout << "Enter the name: ";
    std::cin.getline(cust.fullname, NAME_SIZE);

    std::cout << "Enter the customer's payment: ";
    std::cin >> cust.payment;
    std::cin.get();

    return cust;
}
