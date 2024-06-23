#include <iostream>
#include <cstring>
#include <fstream>

inline void eatLine(){
    while (std::cin.get() != '\n') continue;
}

int main(int argc, char* argv[])
{
    char fileName[40];
    std::cout << "Choose the file:\n";
    std::cin.get(fileName, 40, '\n');
    eatLine();
    std::ofstream outFile;
    outFile.open(fileName);
    std::cout << "Enter your text:\n";
    char info[40];
    while(std::cin.get(info, 40, '\n')){
        outFile << info << "\n";
    }
    outFile.clear();
    outFile.close();

    std::ifstream inFile;
    inFile.open(fileName);
    std::cout << "The file " << fileName << " contains:\n";
    char ch;
    while((ch = inFile.get()) != EOF){
        std::cout << ch;
    }
    return 0;
}
