#include "list.h"

void add_loud(Item& it);

int main(int argc, char* argv[])
{
    List some;

    Item phrase[] =
    {
        "Black Sabbath",
        "Led Zeppelin",
        "Deep Purple",
        "Uriah Heep",
        "Pink Floyd",
        "Iron Maiden",
        "Judas Priest"
    };

    int size = sizeof(phrase)/sizeof(phrase[0]);

    if (some.is_empty())
        for (int i = 0; i < size; ++i)
            some.add(phrase[i]);

    some.show_list();

    std::string str;
    while (!some.is_full())
    {
        std::cout << "Enter your string and it will be added to list: ";
        getline(std::cin, str);
        some.add(str);
    }

    some.show_list();
    some.visit(add_loud);
    some.show_list();

    return 0;

}

void add_loud(Item& it)
{
    it += "!!!";
}
