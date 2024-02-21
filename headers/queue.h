#ifndef QUEUE_H
#define QUEUE_H

bool new_customer(double x);

class Customer
{
private:
    long arrive;
    int processtime;
public:
    Customer();
    void set(long when);
    long when() const;
    int ptime() const;
};

typedef Customer Item;

class Queue
{
    struct Node
    {
        Item item;
        struct Node* next;
    };
    enum {Q_SIZE = 10};

private:
    Node* front;
    Node* rear;
    int items;
    const int qsize;

    Queue(const Queue& q) : qsize(0){}
    Queue& operator=(const Queue& q) {return *this;}

public:
    Queue(int qs = Q_SIZE);
    ~Queue();
    bool isEmpty() const;
    bool isFull() const;
    int queue_count() const;
    bool enQueue(const Item& it);
    bool deQueue(Item& it);
};

#endif // QUEUE_H
