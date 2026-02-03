#include "parser.hpp"
#include "grammar.hpp"

NodeProg* Parser::parse(std::string in) {
    Tokenizer tokenizer;
    index = 0;
    tokens = tokenizer.tokenize(in);
    head = parse_prog();
    return head;
}

inline std::string to_string(TokenType type) {
    switch (type) {
        case (TokenType::INT_LIT):
            return "Integer Literal";
            break;
        case (TokenType::_SEMI):
            return "Semicolon";
            break;
        case (TokenType::_EXIT):
            return "Keyword: 'exit'";
            break;
        default:
            return "";
            break;
        }
    
}

NodeProg* Parser::parse_prog() {
    NodeProg* prog = new NodeProg;
    prog->stmt = parse_stmt();
    return prog;
}

NodeStmt* Parser::parse_stmt() {
    NodeStmt *stmt = new NodeStmt;
    Token first = peek();
    if (first.type == TokenType::_EXIT) {
        NodeStmtExit* exit = new NodeStmtExit;
        exit = parse_exit_stmt();
        stmt->type = *exit;
    }
    return stmt;
}

NodeStmtExit* Parser::parse_exit_stmt() {
    NodeStmtExit* exit = new NodeStmtExit;
	consume(); // consume 'exit'
	try_consume_err(TokenType::_OPEN_PAREN);
	exit->ret = parse_int_lit();
	try_consume_err(TokenType::_CLOSE_PAREN);
	try_consume_err(TokenType::_SEMI);
    std::cout << "Parsed exit statement returning " << exit->ret->val.value.value() << std::endl;
    return exit;
}

NodeIntLit* Parser::parse_int_lit() {
    Token t = try_consume_err(TokenType::INT_LIT).value();
    NodeIntLit* int_lit = new NodeIntLit;
    int_lit->val = t;
    return int_lit;

}

std::optional<Token> Parser::try_consume_err(TokenType type) {
    Token t = peek();
    if (t.type == type) {
        return consume();
    }
    else {
        std::cerr << "Expected " << to_string(type) << " and got " << to_string(t.type) << std::endl;
        return std::nullopt;
    }
}

std::optional<Token> Parser::try_consume(TokenType type) {
    Token t = peek();
    if (t.type == type) {
        return consume();
    }
    else {
        return std::nullopt;
    }

}



Token Parser::peek() {
    if (inRange()) 
    {
        // std::cout << "peeking at " << index << " (in range)" << std::endl;
        return tokens.at(index);
    }
    else {
        // std::cout << "peeking at " << index << " (out of range)" << std::endl;
        Token dummy;
        return dummy; 
    }
    
}

Token Parser::consume() {
    Token t = peek();
    index++;
    return t;

}

bool Parser::inRange() {
    return index >= 0 && index < tokens.size();
}