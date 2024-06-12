#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <set>
#include <iterator>

const int MIN_PER_HOUR = 60;

std::vector<int> Lotto(int total, int setted);

int main(int argc, char* argv[])
{
    srand(time(NULL));
    int total = 0;
    int setted = 0;
    std::ostream_iterator<int> out(std::cout, " ");
    std::cout << "Enter total count of numbers:";
    std::cin >> total;
    std::cout << "Enter count of setted numbers:";
    std::cin >> setted;
    std::cin.clear();
    std::cin.get();
    std::cout << "Got vector:\n";
    std::vector<int> vec = Lotto(total, setted);
    std::copy(vec.begin(), vec.end(), out);
    std::cout << "\n";
    return 0;
}

std::vector<int> Lotto(int total, int setted)
{
    if(setted > total)
        setted = total;
    std::set<int> temp;
    std::vector<int> vec(setted);
    std::insert_iterator<std::set<int>> it(temp, temp.begin());
    for(; temp.size() < setted; ++it)
        it = rand() % total + 1;
    std::copy(temp.begin(), temp.end(), vec.begin());
    return vec;
}
