#pragma once
#include "parser.h"

typedef struct Generator {
    Ast* ast;
} Generator;

char* generate(Generator* generator);
