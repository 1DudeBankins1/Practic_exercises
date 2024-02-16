#include "../headers/stack.h"

Stack::Stack(int n)
{
    if (n > MAX){
        std::cout << "Stack is too large!" << std::endl;
        size = MAX;
    }
    else
        size = n;
    top = 0;
    pitems = new Item[size];
}

Stack::Stack(const Stack& st)
{
    size = st.size;
    top = st.top;
    pitems = new Item[size];
    for (int i = 0; i < top; i++)
        pitems[i] = st.pitems[i];
}

Stack::~Stack()
{
    delete[] pitems;
}

bool Stack::isEmpty() const
{
    return (top == 0);
}

bool Stack::isFull() const
{
    return (top == size);
}

Stack& Stack::operator=(const Stack& st)
{
    if (this == &st)
        return *this;
    size = st.size;
    top = st.top;
    delete[] pitems;
    pitems = new Item[size];
    for (int i = 0; i < top; i++)
        pitems[i] = st.pitems[i];
    return *this;
}

bool Stack::push(const Item &it)
{
    if (isFull()){
        std::cout << "Stack is full!" << std::endl;
        return 0;
    }
    pitems[top++] = it;
    return 1;
}

bool Stack::pop(Item &it)
{
    if (isEmpty()){
        std::cout << "Stack is already empty!" << std::endl;
        return 0;
    }
    it = pitems[--top];
    return 1;
}

std::ostream& operator<<(std::ostream& os, const Stack& st)
{
    os << "The stack contains " << st.top << " items:\n";
    for (int i = 0; i < st.top; ++i)
        cust_show(os, st.pitems[i]);
    os << std::endl;
    return os;
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

void cust_show(std::ostream& os, const customer& cust)
{
    os << "The customer " << cust.fullname << " has " << cust.payment << " bucks\n";
}
