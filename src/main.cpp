#include <iostream>
#include <cstring>
#include <fstream>

inline void eatLine(){
    while (std::cin.get() != '\n') continue;
}

int main(int argc, char* argv[])
{
    char fileName[40];
    std::cout << "Choose files for concatenating:\n";
    std::cin.get(fileName, 40, '\n');
    eatLine();
    std::ifstream cFile1;
    cFile1.open(fileName, std::ios_base::binary | std::ios_base::in);
    if (!cFile1.is_open()){
        std::cerr << "The file isn't found\n";
        exit(1);
    }
    std::cin.get(fileName, 40, '\n');
    eatLine();
    std::ifstream cFile2;
    cFile2.open(fileName, std::ios_base::binary | std::ios_base::in);
    if (!cFile2.is_open()){
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
    while(!cFile1.eof() || !cFile1.eof()){
        if(!cFile1.eof()){
            cFile1.get(ch);
            while(ch != '\n'){
                destFile << ch;
                cFile1.get(ch);
            }
        }
        destFile << ' ';
        if(!cFile2.eof()){
            cFile2.get(ch);
            while(ch != '\n'){
                destFile << ch;
                cFile2.get(ch);
            }
        }
        destFile << std::endl;
    }

    cFile1.clear();
    cFile1.close();
    cFile2.clear();
    cFile2.close();
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
