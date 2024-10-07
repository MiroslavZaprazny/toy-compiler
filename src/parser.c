#include "parser.h"
#include "lexer.h"
#include <stdlib.h>
#include <stdio.h>

Ast* parse(Parser* parser) {
    Ast ast;
    while (1) {
        Token token = next_token(parser->lexer);

        if (token.type = TOKEN_EOF) {
            return &head;
        }

        if (token.type == RETURN) {
            Node* return_node = malloc(sizeof(Node));
            // struct ReturnStatement* stmt = malloc(sizeof(struct ReturnStatement));
            if (return_node == NULL) {
                printf("Failed to allocate memory for the return node\n");
                exit(1);
            }

            Token int_lit_token = next_token(parser->lexer);

            if (int_lit_token.type != INT_LIT) {
                printf("Expected a integer literal after the 'return' keyword got: %s\n", int_lit_token.value); // we should probably print the token type instead of the token value
                exit(1);
            }

            Token semi_token = next_token(parser->lexer);
            if (semi_token.type != SEMICOLON) {
                printf("Expected a semicolon got: %s\n", semi_token.value); // we should probably print the token type instead of the token value
                exit(1);
            }

            return_node.value = int_lit_token;
            return_node.type = NODE_RETURN;

            return stmt;
        }

        printf("Unexpected token: %s\n", token.value);
        exit(1);
    }
}
