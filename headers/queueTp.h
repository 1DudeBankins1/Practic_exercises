#ifndef QUEUETP_H
#define QUEUETP_H
#include<iostream>
template <class Type>
class Queue
{
    struct Node
    {
        Type item;
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
    bool enQueue(const Type& it);
    bool deQueue(Type& it);
    Type& current();
};

template <class Type>
Queue<Type>::Queue(int qs) : qsize(qs)
{
    items = 0;
    front = rear = nullptr;
}

template <class Type>
Queue<Type>::~Queue()
{
    Node* temp;
    while (front != nullptr)
    {
        temp = front->next;
        delete front;
        front = temp;
    }
}

template <class Type>
bool Queue<Type>::isEmpty() const
{
    return (items == 0);
}

template <class Type>
bool Queue<Type>::isFull() const
{
    return (items == qsize);
}

template <class Type>
int Queue<Type>::queue_count() const
{
    return items;
}

template <class Type>
bool Queue<Type>::enQueue(const Type& it)
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

template <class Type>
bool Queue<Type>::deQueue(Type& it)
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

template <class Type>
Type& Queue<Type>::current()
{
    if (!isEmpty())
        return rear->item;
    exit(0);
}

#endif // QUEUETP_H
