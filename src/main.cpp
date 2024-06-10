#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

bool isPalindrome(const std::string& st);

int main()
{
    std::string str;
    bool fail = false;
    std::cout << "Enter the string! Or \"quit\" to quit\n";
    getline(std::cin, str);
    while (str != "quit")
    {
        std::string new_str;
        for (char it : str)
            if (isalpha(it))
                new_str += it;
        transform(new_str.begin(), new_str.end(), new_str.begin(), tolower);
        if (isPalindrome(new_str))
            std::cout << "String \"" << new_str << "\" is palidrome!\n";
        else
            std::cout << "String \"" << new_str << "\" isn't palidrome!\n";
        std::cout << "Enter the string! Or \"quit\" to quit\n";
        getline(std::cin, str);
    }
    std::cout << "Bye!" << '\n';
    return 0;
}

bool isPalindrome(const std::string& st)
{
    size_t sz = st.size();
    int half = (sz / 2) + 1;

    for (int i = 0; i < half ; ++i)
    {
        if (st.at(i) != st.at(sz-1-i))
            return false;
    }
    return true;
}
