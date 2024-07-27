#include <iostream>
#include <cstring>
#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>
#include "../headers/emp.h"

const int SIZE = 5;
const int FILE_SIZE = 40;

inline void eatLine(){
    while (std::cin.get() != '\n') continue;
}

int main(int argc, char* argv[])
{
    Employee* dmitry_emp[SIZE];

    char fileName[FILE_SIZE];
    std::cout << "Choose the file for employee reading:\n";
    std::cin.get(fileName, FILE_SIZE, '\n');
    eatLine();
    int count;
    std::ifstream rEmpFile;
    std::ofstream wrEmpFile;
    rEmpFile.open(fileName, std::ios_base::in);
    if (!rEmpFile.is_open()){
        wrEmpFile.open(fileName);
        for(count = 0; count < SIZE; ++count)
        {
            char choice;
            std::cout << "Enter the guy category: \ne: Employee m: Manager f: Fink h: Highfink q: quit\n";
            std::cin >> choice;
            while (strchr("emfhq", choice) == NULL){
                 std::cout << "Please enter e, m, f, h or q: ";
                 std::cin >> choice;
            }
            if (choice == 'q')
                break;
            switch (choice){
                case 'e': {
                    dmitry_emp[count] = new Employee();
                    break;
                }
                case 'm': {
                    dmitry_emp[count] = new Manager();
                    break;
                }
                case 'f': {
                    dmitry_emp[count] = new Fink();
                    break;
                }
                case 'h': {
                    dmitry_emp[count] = new Highfink();
                    break;
                }
            }
            dmitry_emp[count]->set_all();
            dmitry_emp[count]->write_all(wrEmpFile);
            dmitry_emp[count]->show_all();
        }
        wrEmpFile.clear();
        wrEmpFile.close();
        std::cout << "Creating of file finished\n";
        return 0;
    }
    for(count = 0; (count < SIZE) && !rEmpFile.eof(); ++count)
    {
        std::string post;
        getline(rEmpFile, post);
        switch(empPost(post)){
            case EMPLOYEE: {
                dmitry_emp[count] = new Employee();
                break;
            }
            case MANAGER: {
                dmitry_emp[count] = new Manager();
                break;
            }
            case FINK: {
                dmitry_emp[count] = new Fink();
                break;
            }
            case HIGHFINK: {
                dmitry_emp[count] = new Highfink();
                break;
            }
        }
        dmitry_emp[count]->read_all(rEmpFile);
        dmitry_emp[count]->show_all();
        while (rEmpFile.get() != '\n') continue;
    }
    rEmpFile.clear();
    rEmpFile.close();
    return 0;
}
