#include <iostream>
#include <cstring>
#include <fstream>

inline void eatLine(){
    while (std::cin.get() != '\n') continue;
}

int main(int argc, char* argv[])
{
    char fileName[40];
    std::cout << "Choose the file for copying:\n";
    std::cin.get(fileName, 40, '\n');
    eatLine();
    std::ifstream copyFile;
    copyFile.open(fileName, std::ios_base::binary | std::ios_base::in);
    if (!copyFile.is_open()){
        std::cerr << "The file isn't found\n";
        exit(1);
    }
    std::cout << "Choose the file for destination:\n";
    std::cin.get(fileName, 40, '\n');
    eatLine();
    std::ofstream destFile;
    destFile.open(fileName, std::ios_base::binary | std::ios_base::out | std::ios_base::trunc);
    if (!destFile.is_open()){
        std::cerr << "The file isn't found\n";
        exit(1);
    }
    char ch;
    while(copyFile.get(ch)){
        destFile << ch;
    }
    copyFile.clear();
    copyFile.close();
    destFile.clear();
    destFile.close();

    std::ifstream inFile;
    inFile.open(fileName);
    std::cout << "The file " << fileName << " contains:\n";
    while((ch = inFile.get()) != EOF){
        std::cout << ch;
    }
    std::cout << std::endl;
    inFile.clear();
    inFile.close();

    return 0;
}
