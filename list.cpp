#include "list.h"

List::List()
{
    this->top = 0;
    this->size = 0;
}

bool List::is_empty()
{
    if (top == 0)
        return 1;
    else
        return 0;
}

bool List::is_full()
{
    if (top == MAX)
        return 1;
    else
        return 0;
}

void List::visit(void (*pf)(Item &it))
{
    for (int i = 0; i<top; ++i)
        pf(items[i]);
}

void List::add(Item &it)
{
    if (top < MAX)
        items[top++]=it;
    else
        std::cout << "List is full!\n";
}

void List::show_list()
{
    for (int i = 0; i < top; ++i)
        std::cout << items[i] << std::endl;
    std::cout << std::endl;
}

int List::get_size()
{
    return top;
}

