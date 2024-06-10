#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>

template <typename T>
int reduce(T ar[], int n);

int main()
{
    std::vector<long> long_array;
    long num;
    std::ostream_iterator<long> out(std::cout, " ");
    std::cout << "Enter the numbers! Or \"quit\" to quit\n";
    while (std::cin >> num)
    {
        long_array.push_back(num);
    }
    std::cout << "Entered vector was:\n";
    std::copy(long_array.begin(), long_array.end(), out);
    std::cout << "\nThe conversion vector has "<< reduce(&long_array[0], long_array.size()) << '\n';

    std::vector<std::string> str_array;
    std::string str;
    std::ostream_iterator<std::string> s_out(std::cout, " ");
    std::cout << "Enter the strings! Or \"quit\" to quit\n";
    std::cin.clear();
    std::cin.get();
    std::cin.get();
    getline(std::cin, str);
    while (str != "quit")
    {
        str_array.push_back(str);
        getline(std::cin, str);
    }
    std::cout << "Entered strings was:\n";
    std::copy(str_array.begin(), str_array.end(), s_out);
    std::cout << "\nThe conversion vector has "<< reduce(&str_array[0], str_array.size()) << '\n';
    return 0;
}

template <typename T>
int reduce(T ar[], int n)
{
    std::set<T> s;
    std::copy(ar, ar + n, std::insert_iterator<std::set<T>>(s, s.begin()));
    std::cout << "\n";
    std::copy(s.begin(), s.end(), std::ostream_iterator<T> (std::cout, " "));
    std::cout << "\n";
    return s.size();
}
