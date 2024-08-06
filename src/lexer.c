#include "lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>

struct Token* next_token(struct Lexer* lexer) {
    char* buf = "";
    struct Token* token;

    skip_whitespace(lexer);

    if (isalpha(lexer->input[lexer->position])) {
        while(isalnum(lexer->input[lexer->position])) {
            asprintf(&buf, "%s%c", buf, lexer->input[lexer->position]);
            lexer->position++;
        }

        lexer->position = lexer->position - 1;

        if (strcmp(buf, "return") == 0) {
            token = (Token) {RETURN, NULL};
        }

        buf = "";

        return token;
    } else if (isdigit(lexer->input[lexer->position])) {
        while(isdigit(lexer->input[lexer->position])) {
            asprintf(&buf, "%s%c", buf, lexer->input[lexer->position]);
            lexer->position++;
        }

        lexer->position = lexer->position - 1;

        token = (Token) {INT_LIT, buf};

        buf = "";

        return token;
    } else if (lexer->input[lexer->position] == ';') {
        token = (Token) {SEMICOLON, NULL};
        lexer->position++;

        return token;
    }
}

void skip_whitespace(struct Lexer* lexer) {
    if (isspace(lexer->input[lexer->position])) {
        lexer->position++;
    }
}
