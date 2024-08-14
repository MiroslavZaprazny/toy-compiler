#include "lexer.h"
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Token next_token(struct Lexer* lexer) {
    char* buf = "";
    struct Token token;

    skip_whitespace(lexer);

    if (isalpha(lexer->input[lexer->position])) {
        while(isalnum(lexer->input[lexer->position])) {
            asprintf(&buf, "%s%c", buf, lexer->input[lexer->position]);
            lexer->position++;
        }

        lexer->position = lexer->position - 1;

        if (strcmp(buf, "return") == 0) {
            token.type = RETURN;
            token.value = NULL;
        }

        buf = "";

        return token;
    } else if (isdigit(lexer->input[lexer->position])) {
        while(isdigit(lexer->input[lexer->position])) {
            asprintf(&buf, "%s%c", buf, lexer->input[lexer->position]);
            lexer->position++;
        }

        lexer->position = lexer->position - 1;

        token.type = INT_LIT;
        token.value = buf;

        buf = "";

        return token;
    } else if (lexer->input[lexer->position] == ';') {
        token.type = INT_LIT;
        token.value = buf;

        lexer->position++;

        return token;
    } else if (lexer->input[lexer->position] == '\0') {
        token.type = NULL_PTR;
        token.value = NULL;
    }

    printf("Could not tokenize '%ch' character", lexer->input[lexer->position]);
    exit(1);
}

void skip_whitespace(struct Lexer* lexer) {
    if (isspace(lexer->input[lexer->position])) {
        lexer->position++;
    }
}
