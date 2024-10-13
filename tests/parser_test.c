#include "util.h"
#include"../src/parser.h"
#include"../src/lexer.h"
#include <stdlib.h>

TEST(test_parse_valid_return_statement) {
    char* input = "return 69;";

    Lexer lexer = {input, 0};
    Parser parser = {&lexer};

    Ast* ast = parse(&parser);

    if (ast->len != 1) {
        printf("Expected ast len to be of size %d got %d\n", 1, ast->len);
        exit(1);
    }

    Node node = ast->children[0];

    if (node.type != NODE_RETURN) {
        printf("Expected type '%s' got '%s'\n", "return", node_type_to_str(node.type));
        exit(1);
    }

    if (node.value.int_literal != 69) {
        printf("Expected a integer literal 69 got %d\n", node.value.int_literal);
        exit(1);
    }

    free_tree(ast);
}

int main() {
    RUN_TEST(test_parse_valid_return_statement);
    //TODO: add test for invalid cases

    return 0;
}
