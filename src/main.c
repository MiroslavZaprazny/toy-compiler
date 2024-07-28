#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#include<stdlib.h>

bool is_letter(char c);
struct Token* tokenize(FILE *file);

enum TokenType {
    RETURN,
    SEMICOLON,
};

struct Token {
    enum TokenType type;
    void* value;
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

    fclose(file);

    return 0;
}

struct Token* tokenize(FILE *file) {
    fseek(file, 0L, SEEK_END);
    int file_size = ftell(file);
    rewind(file);

    struct Token* tokens = malloc(5 * sizeof(tokens));

    for (int i = 0; i < file_size; i++) {
        char ch = fgetc(file);
        if (is_letter(ch)) {
            char* buf = "";

            while(is_letter(ch)) {
                asprintf(&buf, "%s%c", buf, ch);
                ch = fgetc(file);
            }

            //TODO: resize array
            if (strcmp(buf, "return") == 0) {
                struct Token token = {RETURN, NULL};
                tokens[i] = token;
            }

            free(buf);
        }
    }

    return tokens;
}

bool is_letter(char ch) {
    return ch >= 'a' && ch <= 'z' || ch >= 'A' && ch <= 'Z';
}
