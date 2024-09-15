#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "src/lexer.h"
#include "src/parser.h"
#include "src/generator.h"

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
    struct Parser parser = {&lexer};
    struct ReturnStatement* return_stmt = (struct ReturnStatement*) parse(&parser);
    struct Generator generator = {return_stmt};

    char* assembly = generate(&generator);
    printf("%s", assembly);

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

    fclose(file);

    return out;
}
