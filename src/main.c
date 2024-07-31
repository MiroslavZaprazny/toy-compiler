#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct Token* tokenize(FILE *file);
char * assemble_tokens(struct Token* tokens);
char* file_to_str(FILE* file);

enum TokenType {
    RETURN,
    SEMICOLON,
    INT_LIT,
};

struct Token {
    enum TokenType type;
    char* value;
};

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

    struct Token* tokens = tokenize(file);
    char* assembly = assemble_tokens(tokens);

    free(tokens);
    fclose(file);

    return 0;
}

char* file_to_str(FILE* file) {
    char * out = "";
    char ch;

    while(ch != EOF) {
        ch = fgetc(file);
        asprintf(&out, "%s%c", out, ch);
    }

    return out;
}

struct Token* tokenize(FILE *file) {
    struct Token* tokens = malloc(3 * sizeof(struct Token));
    char* buf = "";
    int tokensIdx = 0;
    char ch;

    while (ch != EOF) {
        ch = fgetc(file);

        if (isalpha(ch)) {
            while(isalpha(ch)) {
                asprintf(&buf, "%s%c", buf, ch);
                ch = fgetc(file);
            }

            fseek(file, -1, SEEK_CUR);

            //TODO: resize array
            if (strcmp(buf, "return") == 0) {
                struct Token token = {RETURN, NULL};
                tokens[tokensIdx] = token;
                tokensIdx++;
            }

            buf = "";
        } else if (isdigit(ch)) {
            while(isdigit(ch)) {
                asprintf(&buf, "%s%c", buf, ch);
                ch = fgetc(file);
            }

            fseek(file, -1, SEEK_CUR);

            struct Token token = {INT_LIT, buf};
            tokens[tokensIdx] = token;
            tokensIdx++;

            buf = "";
        } else if (ch == ';') {
            struct Token token = {SEMICOLON, NULL};
            tokens[tokensIdx] = token;
            tokensIdx++;
        }
    }

    return tokens;
}


char* assemble_tokens(struct Token* tokens) {
    char* out = "global _start\n_start:";
    int arr_size = sizeof(&tokens);
    int tok_size = sizeof(&tokens[0]);
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
                    printf("Expected a semicolon, got %s", tokens[i+1].value);
                    exit(1);
                }
                asprintf(&out, "%s\n\tmov rax, 60\n\tmov rdi, %s\n\tsyscall\n", out, tokens[i+1].value);
        }
    }

    return out;
}
