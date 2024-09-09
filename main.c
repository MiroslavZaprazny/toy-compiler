#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "src/lexer.h"

char* assemble_tokens(struct Token* tokens);
char* file_to_str(FILE* file);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Missing filename\n");

        return 1;
    }

    char* filename = argv[1];
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Failed to open file");

        return 1;
    }

    struct Lexer lexer = {file_to_str(file), 0};
    struct Token* tokens;
    int i = 0;

    while (true) {
        tokens[i] = next_token(&lexer);

        if (tokens[i].type == _EOF) {
            break;
        }

        i++;
    }

    char* assembly = assemble_tokens(tokens);
    printf("%s", assembly);

    fclose(file);

    return 0;
}

char* file_to_str(FILE* file) {
    char* out = "";

    while (true) {
        char ch = fgetc(file);
        if (ch == EOF) {
            break;
        }

        asprintf(&out, "%s%c", out, ch);
    }

    return out;
}

char* assemble_tokens(struct Token* tokens) {
    char* out = "global _start\n_start:";
    int arr_len = sizeof(&tokens) / sizeof(&tokens[0]);

    for (int i = 0; i < arr_len; i++) {
        struct Token token = tokens[i];

        switch (token.type) {
            case RETURN:
                if (i + 1 < arr_len && tokens[i+1].type != INT_LIT) {
                    printf("Expected a integer, got %s", tokens[i+1].value);
                    exit(1);
                }

                if (i + 2 < arr_len && tokens[i+2].type != SEMICOLON) {
                    printf("Expected a semicolon, got %s", tokens[i+2].value);
                    exit(1);
                }

                asprintf(&out, "%s\n\tmov rax, 60\n\tmov rdi, %s\n\tsyscall\n", out, tokens[i+1].value);
        }
    }

    return out;
}
