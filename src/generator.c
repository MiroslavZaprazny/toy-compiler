#include <stdio.h>
#include "generator.h"

char* generate(Generator* generator) {
    char* out = "global _start\n_start:";
    // todo traverse  the ast
    Node return_node = generator->ast->children[0];
    asprintf(&out, "%s\n\tmov rax, 60\n\tmov rdi, %d\n\tsyscall\n", out, return_node.value.int_literal);

    return out;
}
