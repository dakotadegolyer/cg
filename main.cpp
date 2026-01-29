#include <iostream>
#include <fstream>
#include <iterator>
#include "tokenizer.hpp"


int main() {

    {
    std::fstream inFile("./exit.cg");
    if (!inFile.is_open()) {
        std::cerr << "file not open" << std::endl;
        return 1;
    }
    std::string content((std::istreambuf_iterator<char>(inFile)),
                        std::istreambuf_iterator<char>());
    
    // std::cout << "Contents of file \n" << content << std::endl;
    
    Tokenizer tokenizer(content);
    tokenizer.tokenize();
    }

    return 0;
}