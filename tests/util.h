#include "../src/lexer.h"
#include <stdio.h>

#define TEST(name) void name()
#define RUN_TEST(name) printf("Running test: %s \n", #name); name(); printf("Test passed\n")

char* token_type_to_str(TokenType type);
