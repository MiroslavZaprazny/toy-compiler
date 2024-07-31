enum TokenType {
    RETURN,
    SEMICOLON,
    INT_LIT,
};

struct Token {
    enum TokenType type;
    char* value;
};

struct Lexer {
    char* input;
    int position;
}

struct Token* next_token(struct Lexer* lexer) {
    char* buf = "";
    struct Token token;

    skip_whitespace(lexer);

    if (isalpha(lexer.input[lexer.position])) {
        while(isalpha(lexer.input[lexer.position])) {
            asprintf(&buf, "%s%c", buf, lexer.input[lexer.position]);
            lexer.position++;
        }

        lexer.position = lexer.position - 1;

        if (strcmp(buf, "return") == 0) {
            token = {RETURN, NULL};
        }

        buf = "";

        return &token;
    } else if (isdigit(ch)) {
        while(isdigit(ch)) {
            asprintf(&buf, "%s%c", buf, ch);
            lexer.position++;
        }

        lexer.position = lexer.position - 1;

        token = {INT_LIT, buf};

        buf = "";

        return token;
    } else if (ch == ';') {
        token = {SEMICOLON, NULL};
        lexer.position++;

        return token;
    }
}

skip_whitespace(struct Lexer* lexer) {
    if (isspace(lexer.input[lexer.position])) {
        lexer.position++;
    }
}
