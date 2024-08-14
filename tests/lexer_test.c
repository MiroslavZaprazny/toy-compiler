#include<stdio.h>
#include<stdlib.h>
#include"../src/lexer.h"

#define TEST(name) void name()
#define RUN_TEST(name) printf("Running test: %s \n", #name); name(); printf("Test passed\n")

char* token_type_to_str(enum TokenType type) {
    switch(type) {
        case RETURN:
            return "return";
    }
}

TEST(tokenize_valid_return_statement) {
    char* input = "return 60;";
    struct Lexer lexer = {input, 0};

    struct Token return_token = next_token(&lexer);
    if (return_token.type != RETURN) {
        printf("Expected token type '%s' got '%s'\n", "return", token_type_to_str(return_token.type));
        exit(1);
    }

    // TODO: add more test cases
}

int main() {
    RUN_TEST(tokenize_valid_return_statement);

    return 0;
}
