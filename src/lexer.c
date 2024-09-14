#include "lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Token next_token(struct Lexer* lexer) {
    char* buf = "";
    struct Token token;

    skip_whitespace(lexer);

    if (isalpha(peek(lexer)) {
        while(isalnum(peek(lexer)) {
            asprintf(&buf, "%s%c", buf, peek(lexer));
            lexer->position++;
        }

        if (strcmp(buf, "return") == 0) {
            token.type = RETURN;
            token.value = NULL;
        }
        buf = "";

        return token;
    } else if (isdigit(peek(lexer)) {
        while(isdigit(peek(lexer)) {
            asprintf(&buf, "%s%c", buf, peek(lexer));
            lexer->position++;
        }

        token.type = INT_LIT;
        token.value = buf;

        buf = "";

        return token;
    } else if (peek(lexer) == ';') {
        token.type = SEMICOLON;
        token.value = NULL;

        lexer->position++;

        return token;
    } else if (peek(lexer) == '\0') {
        token.type = _EOF;
        token.value = NULL;

        return token;
    }

    printf("Could not tokenize '%c' character\n", peek(lexer));
    exit(1);
}

char peek(struct Lexer* lexer) {
    return lexer->input[lexer->position];
}

void skip_whitespace(struct Lexer* lexer) {
    if (isspace(lexer->input[lexer->position])) {
        lexer->position++;
    }
}
