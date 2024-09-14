#include "parser.h"
#include "lexer.h"

struct ReturnStatement* parse(struct Parser* parser) {
    if (next_token(parser->lexer).type == TokenType::RETURN) {
        ReturnStatement stmt;
        int_lit = next_token(parser->lexer);

        if (int_lit != TokenType::INT_LIT) {
            printf("Expected a integer literal after the 'reutrn' keyword got: %s", int_lit.value) // we should probably print the token type instead of the token value
            exit(1);
        }

        semi = next_token(parser->lexer);
        if (semi != TokenType::SEMICOLON) {
            printf("Expected a semicolon got: %s", int_lit.value) // we should probably print the token type instead of the token value
            exit(1);
        }

        Expression expression = {int_lit}:
        stmt.expression = &expression;

        return stmt;
    }
}
