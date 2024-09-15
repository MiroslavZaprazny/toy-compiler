#pragma once

enum TokenType {
    RETURN,
    SEMICOLON,
    INT_LIT,
    _EOF,
};

struct Token {
    enum TokenType type;
    char* value;
};

struct Lexer {
    char* input;
    int position;
};

struct Token next_token(struct Lexer* lexer);
void skip_whitespace(struct Lexer* lexer);
char peek(struct Lexer* lexer);
