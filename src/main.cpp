#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <iterator>
#include <algorithm>

inline void eatLine(){
    while (std::cin.get() != '\n') continue;
}

int main(int argc, char* argv[])
{
    std::ostream_iterator<std::string> out(std::cout, " ");
    std::cout << "Matt, enter your filename:\n";

    char fileName[40];
    std::cin.get(fileName, 40, '\n');
    eatLine();
    std::ifstream mattsFile;
    mattsFile.open(fileName, std::ios_base::in);
    if (!mattsFile.is_open()){
        std::cerr << "The file isn't found\n";
        exit(1);
    }

    std::set<std::string> matts;
    std::string temp;
    while(getline(mattsFile, temp)){
        matts.insert(temp);
    }

    std::cout << "Patt, enter your filename:\n";
    std::cin.get(fileName, 40, '\n');
    eatLine();
    std::ifstream pattsFile;
    pattsFile.open(fileName);
    if (!pattsFile.is_open()){
        std::cerr << "The file isn't found\n";
        exit(1);
    }
    std::set<std::string> patts;
    while(getline(pattsFile, temp)){
        patts.insert(temp);
    }

    std::cout << "Choose the file for destination:\n";
    std::cin.get(fileName, 40, '\n');
    eatLine();
    std::ofstream destFile;
    destFile.open(fileName, std::ios_base::out | std::ios_base::trunc);
    if (!destFile.is_open()){
        std::cerr << "The file isn't found\n";
        exit(1);
    }

    std::set<std::string> united;
    std::insert_iterator<std::set<std::string>>it(united, united.begin());
    std::set_union(matts.begin(), matts.end(), patts.begin(), patts.end(), it);

    for (auto itt : united){
        destFile << itt << std::endl;
    }

    std::cout << "\nMatt's list: ";
    std::copy(matts.begin(), matts.end(), out);

    std::cout << "\nPatt's list: ";
    std::copy(patts.begin(), patts.end(), out);

    std::cout << "\nUnited list: ";
    std::copy(united.begin(), united.end(), out);

    mattsFile.clear();
    mattsFile.close();
    pattsFile.clear();
    pattsFile.close();
    destFile.clear();
    destFile.close();

    std::ifstream inFile;
    inFile.open(fileName);
    std::cout << '\n';
    std::cout << "The file " << fileName << " contains:";
    while(getline(inFile, temp)){
        std::cout << temp << '\n';
    }
    std::cout << std::endl;
    inFile.clear();
    inFile.close();

    return 0;
}
