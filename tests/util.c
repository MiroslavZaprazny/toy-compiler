#include"../src/lexer.h"
#include"../src/parser.h"

char* token_type_to_str(TokenType type) {
    switch(type) {
        case TOKEN_RETURN:
            return "return";
        case TOKEN_INT_LIT:
            return "int literal";
        case TOKEN_SEMICOLON:
            return "semicolon";
        case TOKEN_EOF:
            return "eof";
    }
}

char* node_type_to_str(NodeType type) {
    switch(type) {
        case NODE_RETURN:
            return "return node";
    }
}
