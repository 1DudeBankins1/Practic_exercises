#include "../headers/queue.h"
#include<cstdlib>

bool new_customer(double x)
{
    return (rand() * x / RAND_MAX < 1);
}

Customer::Customer()
{
    arrive = processtime = 0;
}

void Customer::set(long when)
{
    processtime = rand() % 3 + 1;
    arrive = when;
}

long Customer::when() const
{
    return arrive;
}

int Customer::ptime() const
{
    return processtime;
}

Queue::Queue(int qs) : qsize(qs)
{
    items = 0;
    front = rear = nullptr;
}

Queue::~Queue()
{
    Node* temp;
    while (front != nullptr)
    {
        temp = front->next;
        delete front;
        front = temp;
    }
}

bool Queue::isEmpty() const
{
    return (items == 0);
}

bool Queue::isFull() const
{
    return (items == qsize);
}

int Queue::queue_count() const
{
    return items;
}

bool Queue::enQueue(const Item& it)
{
    if (isFull())
        return 0;
    Node* new_cust = new Node;
    if (new_cust == nullptr)
        return 0;
    new_cust->item = it;
    new_cust->next = nullptr;
    if (isEmpty())
        rear = front = new_cust;
    else{
        rear->next = new_cust;
        rear = new_cust;
    }
    items++;
    return 1;
}

bool Queue::deQueue(Item& it)
{
    if (isEmpty())
        return 0;
    it = front->item;
    Node* temp = front;
    items--;
    if (isEmpty())
        front = rear = nullptr;
    else
        front = temp->next;
    delete temp;
    return 1;
}
