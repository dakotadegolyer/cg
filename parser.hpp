#pragma once
#include "grammar.hpp"
#include "tokenizer.hpp"

class Parser {
private:
    std::vector<Token> tokens;
    //std::vector<Node> stack;
    NodeProg* head;
    int index;
    
    
    NodeProg* parse_prog();
    NodeStmt* parse_stmt();
    NodeStmtExit* parse_exit_stmt();
    NodeIntLit* parse_int_lit();

    std::optional<Token> try_consume(TokenType type);
    std::optional<Token> try_consume_err(TokenType type);
    Token peek();
    Token consume();
    bool inRange();

public:
    NodeProg* parse(std::string in);

};




