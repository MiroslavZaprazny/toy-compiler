#include "lexer.h"

struct Expression {
    int int_lit; // for now we just support expressions that only contain a single integer literal
};

struct ReturnStatement {
    Token* token;
    Expression* expression;
};

struct Parser {
    Lexer* lexer;
};

void* parse(struct Parser* parser);

// struct ParseTree {
//     void* expressions;
// };
