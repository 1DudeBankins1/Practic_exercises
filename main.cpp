#include "move.h"
#include <iostream>
#include <cctype>

using namespace std;

int main(int argc, char* argv[])
{

    Move m_1(25, 36.6);
    Move m_2(17.5, 284);

    std::cout << "m_1 = " << std::endl;
    m_1.showmore();

    std::cout << "m_2 = " << std::endl;
    m_2.showmore();

    Move m_3 = m_2.add(m_1);
    std::cout << "m_3 = m_2 add m_1:" << std::endl;
    m_3.showmore();

    std::cout << "m_2 reset = " << std::endl;
    m_2.reset(10,10);
    m_2.showmore();

    std::cout << "m_3 add m_2:" << std::endl;
    Move m_4 = m_3.add(m_2);
    m_4.showmore();
    return 0;
}
