#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../src/lexer.h"

#define TEST(name) void name()
#define RUN_TEST(name) printf("Running test: %s \n", #name); name(); printf("Test passed\n")

char* token_type_to_str(enum TokenType type) {
    switch(type) {
        case RETURN:
            return "return";
        case INT_LIT:
            return "int literal";
        case SEMICOLON:
            return "semicolon";
        case _EOF:
            return "eof";
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

    if (return_token.value != NULL) {
        printf("Expected token value to be'NULL' got '%s'\n", return_token.value);
        exit(1);
    }

    struct Token int_token = next_token(&lexer);
    if (int_token.type != INT_LIT) {
        printf("Expected token type '%s' got '%s'\n", "int literal", token_type_to_str(int_token.type));
        exit(1);
    }

    if (strcmp(int_token.value, "60")) {
        printf("Expected token value to be '60' got '%s'\n", int_token.value);
        exit(1);
    }

    struct Token semi = next_token(&lexer);
    if (semi.type != SEMICOLON) {
        printf("Expected token type '%s' got '%s'\n", "semicolon", token_type_to_str(semi.type));
        exit(1);
    }

    if (semi.value != NULL) {
        printf("Expected token value to be 'NULL' got '%s'\n", semi.value);
        exit(1);
    }

    struct Token eof = next_token(&lexer);
    if (eof.type != _EOF) {
        printf("Expected token type '%s' got '%s'\n", "EOF", token_type_to_str(eof.type));
        exit(1);
    }

    if (eof.value != NULL) {
        printf("Expected token value to be 'NULL' got '%s'\n", eof.value);
        exit(1);
    }
}

int main() {
    RUN_TEST(tokenize_valid_return_statement);

    return 0;
}
