#pragma once

#include "lexer.h"

typedef union NodeValue {
    int int_literal;
} NodeValue;

typedef enum NodeType {
    NODE_RETURN,
} NodeType;

typedef struct Node {
    NodeValue value;
    NodeType type;
    // Node* expr;
    // Node* right;
    // Node* left;
} Node;

typedef struct Ast {
    Node* children;
    int len;
} Ast;

typedef struct Parser {
    Lexer* lexer;
} Parser;

Ast* parse(Parser* parser);

