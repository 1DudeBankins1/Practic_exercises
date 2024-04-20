#include <iostream>
#include <cstring>
#include "../headers/emp.h"

const int SIZE = 5;

int main()
{
    Employee th("Trip", "Harris", "Thumper");
    std::cout << th;
    th.show_all();

    Manager db("Debbie", "Bolt", "Twigger", 5);
    std::cout << db;
    db.show_all();

    Fink mo("Matt", "Oggs", "Oiler", "Debbie Bolt");
    std::cout << mo;
    mo.show_all();

    Highfink hf(db, "Curly Kew");
    std::cout << hf;
    hf.show_all();

    std::cout << "Using an employee * pointer:\n";
    Employee *tri[4] = {&th, &db, &mo, &hf};
    for (int i = 0; i < 4; ++i)
        tri[i]->show_all();

    std::cin.get();

    Employee th_2;
    th_2.set_all();
    Manager db_2;
    db_2.set_all();
    Fink mo_2;
    mo_2.set_all();
    Highfink hf_2;
    hf_2.set_all();
    Employee *tri_2[4] = {&th_2, &db_2, &mo_2, &hf_2};
    for (int i = 0; i < 4; ++i)
        tri_2[i]->show_all();

    return 0;
}
