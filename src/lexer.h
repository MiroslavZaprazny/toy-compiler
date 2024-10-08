#pragma once

typedef enum TokenType {
    TOKEN_RETURN,
    TOKEN_SEMICOLON,
    TOKEN_INT_LIT,
    TOKEN_EOF,
} TokenType;

typedef struct Token {
    enum TokenType type;
    char* value;
} Token;

typedef struct Lexer {
    char* input;
    int position;
} Lexer;

Token next_token(Lexer* lexer);
void skip_whitespace(Lexer* lexer);
char peek(Lexer* lexer);
