#pragma once
#include <argp.h>
#include <stdlib.h>
#include "Defines.h"
struct arguments {
    int root;
    int iterations;
    char *test_root;
    char *test_integral;
};

extern struct arguments arguments;

struct root_params {
    mathFunc* f;
    mathFunc* g;
    double a;
    double b;
    double eps1;
    mathFunc* f_deriv;
    mathFunc* g_deriv;
    double result;
};
extern struct root_params root_params;

struct integral_params {
    mathFunc* f;
    double a;
    double b;
    double eps2;
    double result;
};
extern struct integral_params integral_params;

void ParseArgs(int argc, char **argv);