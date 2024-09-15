#pragma once
#include "parser.h"

struct Generator {
    struct ReturnStatement* stmt; // for now we just support return statements
};

char* generate(struct Generator* generator);
