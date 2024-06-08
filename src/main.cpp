#include <iostream>
#include <string>
#include <cctype>

bool isPalindrome(const std::string& st);

int main()
{
    std::string str;
    bool fail = false;
    std::cout << "Enter the string! Or \"quit\" to quit\n";
    getline(std::cin, str);
    while (str != "quit")
    {
        for (char it : str) {
            if (!isalpha(it) || isupper(it))
            {
                std::cout << "String contains uncorrect symbols, try again!" << '\n';
                getline(std::cin, str);
                fail = true;
                break;
            }
        }
        if (fail){
            fail = false;
            continue;
        }
        if (isPalindrome(str))
            std::cout << "String is palidrome!\n";
        else
            std::cout << "String isn't palidrome!\n";
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
