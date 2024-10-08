#include <stdio.h>
#include "generator.h"

char* generate(Generator* generator) {
    char* out = "global _start\n_start:";
    for (int i = 0; i < generator->ast->len; i ++) {
        Node node = generator->ast->children[i];

        if (node.type == NODE_RETURN) {
            asprintf(&out, "%s\n\tmov rax, 60\n\tmov rdi, %d\n\tsyscall\n", out, node.value.int_literal);
        }
    }

    return out;
}
