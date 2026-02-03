#pragma once
#include <variant>
#include "tokenizer.hpp"

// statements
struct NodeProg;

struct NodeStmt;
struct NodeStmtExit;

struct NodeIntLit;



// definitions
struct NodeStmtExit {
    Token *ret;
};

struct NodeStmt {
    std::variant<NodeStmtExit> type;
};

struct NodeProg {
    NodeStmt *stmt;
};

struct NodeIntLit {
    Token val;
};
// functions





