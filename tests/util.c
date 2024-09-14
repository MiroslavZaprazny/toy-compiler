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
