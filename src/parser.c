#include "parser.h"
#include "lexer.h"
#include <stdlib.h>
#include <stdio.h>

Ast* parse(Parser* parser) {
    Ast* ast = malloc(sizeof(Ast));
    ast->len = 1;
    ast->children = malloc(sizeof(Node) * ast->len); //TODO: We should probably allocate more memory?

    // Todo: Implement realocating the children when we reach the capacity
    int i = 0;
    while (1) {
        Token token = next_token(parser->lexer);

        if (token.type == TOKEN_EOF) {
            return ast;
        }

        if (token.type == TOKEN_RETURN) {
            Token int_lit_token = next_token(parser->lexer);
            if (int_lit_token.type != TOKEN_INT_LIT) {
                printf("Expected a integer literal after the 'return' keyword got: %s\n", int_lit_token.value); // we should probably print the token type instead of the token value
                exit(1);
            }

            Token semi_token = next_token(parser->lexer);
            if (semi_token.type != TOKEN_SEMICOLON) {
                printf("Expected a semicolon got: %s\n", semi_token.value); // we should probably print the token type instead of the token value
                exit(1);
            }

            Node* return_node = malloc(sizeof(Node));
            if (return_node == NULL) {
                printf("Failed to allocate memory for the return node\n");
                exit(1);
            }

            return_node->type = NODE_RETURN;
            NodeValue val = {.int_literal = atoi(int_lit_token.value)};
            return_node->value = val;
            ast->children[i] = *return_node;

            i++;
            continue;
        }

        printf("Unexpected token: %s\n", token.value);
        exit(1);
    }
}

void free_tree(Ast* ast) {
    for (int i = 0; i < ast->len; i++) {
        //TODO: in the future we will need to also free up nested nodes
        Node* node = &ast->children[i];
        free(node);
    }

    free(ast);
}
