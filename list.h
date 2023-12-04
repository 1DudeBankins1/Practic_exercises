#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <cstring>

typedef std::string Item;

class List
{
private:
    enum {MAX = 10};
    Item items[MAX];
    int top;
    int size;
public:
    List();
    bool is_empty();
    bool is_full();
    void visit(void(*pf)(Item&));
    void add(Item&);
    void show_list();
    int get_size();
};

#endif // LIST_H
