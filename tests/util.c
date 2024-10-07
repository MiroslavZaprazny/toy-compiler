#include"../src/lexer.h"

char* token_type_to_str(TokenType type) {
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
