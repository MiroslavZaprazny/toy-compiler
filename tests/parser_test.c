#include "util.h"
#include"../src/lexer.h"
#include"../src/parser.h"

TEST(test_parse_valid_return_statement) {
    char* input = "return 69;";

    Lexer lexer = {input, 0};
    Parser parser = {&lexer};

    ReturnStatement return_stmt = (struct ReturnStatement*) parse(&parser);

    if (return_tmt.token.TokenType != TokenType::RETURN) {
        printf("Expected token type '%s' got '%s'\n", "return", token_type_to_str(return_token.type));
        exit(1);
    }

    if (return_tmt.expression.int_lit != 69) {
        printf("Expected a integer literal '69' got '%s'\n", token_type_to_str(return_token.type));
        exit(1);
    }
}

int main() {
    RUN_TEST(test_parse_valid_return_statement);

    return 0;
}
