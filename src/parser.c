#include"parser.h"
#include"lexer.h"
#include <stdlib.h>
#include <stdio.h>

void* parse(struct Parser* parser) {
    struct Token token = next_token(parser->lexer);

    if (token.type == RETURN) {
        struct ReturnStatement* stmt = malloc(sizeof(struct ReturnStatement));
        if (stmt == NULL) {
            printf("Failed to allocate memory for the return statement structure\n");
            exit(1);
        }

        struct Token int_lit_token = next_token(parser->lexer);

        if (int_lit_token.type != INT_LIT) {
            printf("Expected a integer literal after the 'reutrn' keyword got: %s\n", int_lit_token.value); // we should probably print the token type instead of the token value
            exit(1);
        }

        struct Token semi_token = next_token(parser->lexer);
        if (semi_token.type != SEMICOLON) {
            printf("Expected a semicolon got: %s\n", semi_token.value); // we should probably print the token type instead of the token value
            exit(1);
        }

        struct Expression expression = {atoi(int_lit_token.value)};
        stmt->expression = expression;
        stmt->token = token;

        return (void*)stmt;
    }

    printf("Unexpected token: %s\n", token.value);
    exit(1);
}
