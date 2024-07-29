#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

struct Token* tokenize(FILE *file);
char * assemble_tokens(struct Token* tokens);

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

    free(tokens);
    fclose(file);

    return 0;
}

struct Token* tokenize(FILE *file) {
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    struct Token* tokens = malloc(3 * sizeof(struct Token));
    char* buf = "";
    int tokensIdx = 0;

    for (int i = 0; i < file_size; i++) {
        char ch = fgetc(file);

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
    char* out = "";

    return out;
}
