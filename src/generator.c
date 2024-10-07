#include <stdio.h>
#include "generator.h"

char* generate(Generator* generator) {
    char* out = "global _start\n_start:";
    asprintf(&out, "%s\n\tmov rax, 60\n\tmov rdi, %d\n\tsyscall\n", out, generator->stmt->expression.int_lit);

    return out;
}
