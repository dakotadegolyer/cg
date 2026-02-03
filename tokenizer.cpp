#include "tokenizer.hpp"


Tokenizer::Tokenizer() {
}

std::string Tokenizer::tokenToString(Token t) {
    if (t.value.has_value()) {
        return t.value.value();
    }
    else if (t.type == TokenType::_EXIT) {
        return "EXIT";
    }
    else if (t.type == TokenType::_SEMI) {
        return "SEMI";
    }
    else {
        return "UNKNOWN_TOKEN";
    }
}

std::vector<Token> Tokenizer::tokenize(std::string in) {
    input = in;
    tokens = std::vector<Token>();
    index = 0;
    buf = "";

    char c;
    while (inRange()) {
        // std::cout << "index = " << index << std::endl;
        // std::cout << "c = " << peek() << std::endl;
        c = peek();

        // if we are parsing a number
        if (isdigit(c)) { 
            consume();
            c = peek();

            while(isdigit(c)) {
                consume();
                c = peek();
            }
            tokens.push_back({TokenType::INT_LIT, buf});
            buf.clear();
        }
        else if (isalpha(c)) {
            consume();
            c = peek();
            while (isalnum(c)) {
                consume();
                c = peek();
            }
            if (buf == "exit") {
                tokens.push_back({TokenType::_EXIT});
                discard();
                buf.clear();
            }
        }
        else if (c == ';') {
            discard();
            tokens.push_back({TokenType::_SEMI});
        }   
        else if (isspace(c)){
            discard();
        }
        else {
            std::cerr << "Unrecognized character";
        }
    }
    return tokens;
    
}

void Tokenizer::printTokens() {
    for (Token t : tokens) {
            std::cout << tokenToString(t) << ", ";
    }
    std::cout << std::endl;
}

bool Tokenizer::inRange() {
    return (index >= 0) && (index < input.size());
}




