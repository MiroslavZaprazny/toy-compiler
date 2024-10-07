#include "util.h"
#include"../src/parser.h"
#include"../src/lexer.h"
#include <stdlib.h>

TEST(test_parse_valid_return_statement) {
    char* input = "return 69;";

    Lexer lexer = {input, 0};
    Parser parser = {&lexer};

    ReturnStatement* return_stmt = (struct ReturnStatement*) parse(&parser);

    if (return_stmt->token.type != RETURN) {
        printf("Expected token type '%s' got '%s'\n", "return", token_type_to_str(return_stmt->token.type));
        exit(1);
    }

    if (return_stmt->expression.int_lit != 69) {
        printf("Expected a integer literal '69' got '%s'\n", token_type_to_str(return_stmt->token.type));
        exit(1);
    }

    free(return_stmt);
}

int main() {
    RUN_TEST(test_parse_valid_return_statement);
    //TODO: add test for invalid cases

    return 0;
}
