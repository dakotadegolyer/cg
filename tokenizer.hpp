#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <optional>
#include <stdexcept>

enum class TokenType {
    _EXIT,
    INT_LIT,
    _SEMI
};

struct Token {
    TokenType type;
    std::optional<std::string> value;

};

class Tokenizer {
private:
    std::string input;
    std::vector<Token> tokens;
    std::string buf;
    int index;

    
    inline void discard(int offset = 0) {
        index++;
        index += offset;
    }

    inline void consume(int offset = 0) {
        for (int i = 0; i <= offset; i++) {
            buf.push_back(peek());
            index++;
        }
    }

    inline char peek(int offset = 0) {
        if (index + offset > input.length()) {
            throw std::out_of_range("Error reading input, index out of bounds");
        }
        else {
            return input.at(index + offset);
        }
    }
    std::string tokenToString(Token t);
    bool inRange();

public:
    Tokenizer(std::string in);
    void tokenize();

};

