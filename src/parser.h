#pragma once

#include "lexer.h"

struct Expression {
    int int_lit; // for now we just support expressions that only contain a single integer literal
};

struct ReturnStatement {
    struct Token token; // do we even need this?
    struct Expression expression;
};

struct Parser {
    struct Lexer* lexer;
};

void* parse(struct Parser* parser);

