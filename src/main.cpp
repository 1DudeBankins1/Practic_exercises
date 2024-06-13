#include <iostream>
#include <set>
#include <iterator>
#include <algorithm>

int main(int argc, char* argv[])
{
    std::ostream_iterator<std::string> out(std::cout, " ");
    std::cout << "Matt, enter your list, enter \"end\" to end:\n";
    std::set<std::string> matts;
    std::string temp;
    getline(std::cin, temp);
    while(temp != "end")
    {
        matts.insert(temp);
        getline(std::cin, temp);
    }

    std::cout << "Patt, enter your list, enter \"end\" to end:\n";
    std::set<std::string> patts;
    getline(std::cin, temp);
    while(temp != "end")
    {
        patts.insert(temp);
        getline(std::cin, temp);
    }

    std::set<std::string> united;
    std::insert_iterator<std::set<std::string>>it(united, united.begin());
    std::set_union(matts.begin(), matts.end(), patts.begin(), patts.end(), it);

    std::cout << "\nMatt's list: ";
    std::copy(matts.begin(), matts.end(), out);

    std::cout << "\nPatt's list: ";
    std::copy(patts.begin(), patts.end(), out);

    std::cout << "\nUnited list: ";
    std::copy(united.begin(), united.end(), out);

    return 0;
}
