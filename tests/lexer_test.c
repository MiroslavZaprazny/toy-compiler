#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"../src/lexer.h"
#include"util.h"

TEST(tokenize_valid_return_statement) {
    char* input = "return 60;";
    Lexer lexer = {input, 0};

    Token return_token = next_token(&lexer);
    if (return_token.type != TOKEN_RETURN) {
        printf("Expected token type '%s' got '%s'\n", "return", token_type_to_str(return_token.type));
        exit(1);
    }

    if (return_token.value != NULL) {
        printf("Expected token value to be'NULL' got '%s'\n", return_token.value);
        exit(1);
    }

    Token int_token = next_token(&lexer);
    if (int_token.type != TOKEN_INT_LIT) {
        printf("Expected token type '%s' got '%s'\n", "int literal", token_type_to_str(int_token.type));
        exit(1);
    }

    if (strcmp(int_token.value, "60")) {
        printf("Expected token value to be '60' got '%s'\n", int_token.value);
        exit(1);
    }

    Token semi = next_token(&lexer);
    if (semi.type != TOKEN_SEMICOLON) {
        printf("Expected token type '%s' got '%s'\n", "semicolon", token_type_to_str(semi.type));
        exit(1);
    }

    if (semi.value != NULL) {
        printf("Expected token value to be 'NULL' got '%s'\n", semi.value);
        exit(1);
    }

    Token eof = next_token(&lexer);
    if (eof.type != TOKEN_EOF) {
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
