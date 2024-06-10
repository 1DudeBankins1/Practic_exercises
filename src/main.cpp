#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
#include <set>
#include <vector>
#include <iterator>

int reduce(long ar[], int n);

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
    return 0;
}

int reduce(long ar[], int n)
{
    std::set<long> s;
    std::copy(ar, ar + n, std::insert_iterator<std::set<long>>(s, s.begin()));
    std::cout << "\n";
    std::copy(s.begin(), s.end(), std::ostream_iterator<long> (std::cout, " "));
    std::cout << "\n";
    return s.size();
}
