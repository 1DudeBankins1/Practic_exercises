#include "stack.h"
#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, char* argv[])
{
    Stack st;
    char c;
    customer cust;
    std::cout << "Enter A to add a customer, D to delete a customer, Q to quit\n";

    while ((std::cin >> c) && (toupper(c) != 'Q')){
        while(std::cin.get() != '\n')
            continue;
        if (!isalpha(c)){
            std::cout << "Retry!\a";
            continue;
        }
        switch (c){
            case 'a': case 'A':
            {
                cust = create_cust();
                if (!st.pushback(cust))
                    continue;
                break;
            }
            case 'd': case 'D':
            {
                if(!st.popback(cust))
                    continue;
                break;
            }
        }
        std::cout << "Enter A to add a customer, D to delete a customer, Q to quit\n";
    }
    std::cout << "Quit" << std::endl;
    return 0;
}
