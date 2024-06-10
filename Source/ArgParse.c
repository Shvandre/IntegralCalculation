#include <stdio.h>
#include <argp.h>
#include <string.h>
#include "ArgParse.h"
#include "Defines.h"
#include "MathFunctions.h"

struct arguments arguments;
struct root_params root_params;
struct integral_params integral_params;

const char *argp_program_version = "1.0";
const char *argp_program_bug_address = "anevshvets@edu.hse.ru";
static char doc[] = "Educational program for finding the area bounded by 3 graphs";

static char args_doc[] = "";

static struct argp_option options[] = {
        {"root", 'r', 0, 0, "Print the x-coordinates of the intersections.", 0},
        {"iterations", 'i', 0, 0, "Print the number of iterations needed.", 0},
        {"test-root", 'R', "F1:F2:A:B:E:R", 0, "Test the root function with parameters.", 0},
        {"test-integral", 'I', "F:A:B:E:R", 0, "Test the integral function with parameters.", 0},
        {"myhelp", 'h', 0, 0, "Print help.", 0},
        {0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state) {
    struct arguments *my_arg = state->input;

    switch (key) {
        case 'r':
            my_arg->root = 1;
            break;
        case 'h':
            printf("Usage: ./integral [OPTIONS...]\n");
            exit(0);
        case 'i':
            my_arg->iterations = 1;
            break;
        case 'R':
            my_arg->test_root = arg;
            break;
        case 'I':
            my_arg->test_integral = arg;
            break;
        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

static struct argp argp = {options, parse_opt, args_doc, doc, 0, 0, 0};

static mathFunc* GetFuncByName(char *name, int deriv) {
    if (strcmp(name, "F1") == 0) {
        if (deriv) {
            return f1_deriv;
        }
        return f1;
    } else if (strcmp(name, "F2") == 0) {
        if (deriv) {
            return f2_deriv;
        }
        return f2;
    } else if (strcmp(name, "F3") == 0) {
        if (deriv) {
            return f3_deriv;
        }
        return f3;
    }
    else {
        perror("Met unknown function name while parsing arguments. Exiting...");
        exit(0);
    }
}

static void ParseRootParams(char *arg) {
    char *token = strtok(arg, ":");
    root_params.f = GetFuncByName(token, 0);
    root_params.f_deriv = GetFuncByName(token, 1);
    token = strtok(NULL, ":");
    root_params.g = GetFuncByName(token, 0);
    root_params.g_deriv = GetFuncByName(token, 1);
    token = strtok(NULL, ":");
    root_params.a = atof(token);
    token = strtok(NULL, ":");
    root_params.b = atof(token);
    token = strtok(NULL, ":");
    root_params.eps1 = atof(token);
    token = strtok(NULL, ":");
    root_params.result = atof(token);
}

static void ParseIntegralParams(char *arg) {
    char *token = strtok(arg, ":");
    integral_params.f = GetFuncByName(token, 0);
    token = strtok(NULL, ":");
    integral_params.a = atof(token);
    token = strtok(NULL, ":");
    integral_params.b = atof(token);
    token = strtok(NULL, ":");
    integral_params.eps2 = atof(token);
    token = strtok(NULL, ":");
    integral_params.result = atof(token);
}
void ParseArgs(int argc, char **argv) {
    arguments.root = 0;
    arguments.iterations = 0;
    arguments.test_root = NULL;
    arguments.test_integral = NULL;

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    if (arguments.root) {
        printf("Print roots option selected.\n");
    }

    if (arguments.iterations) {
        printf("Print iterations option selected.\n");
    }

    if (arguments.test_root) {
        printf("Testing root function with parameters: %s\n", arguments.test_root);
        ParseRootParams(arguments.test_root);
    }

    if (arguments.test_integral) {
        printf("Testing integral function with parameters: %s\n", arguments.test_integral);
        ParseIntegralParams(arguments.test_integral);
    }
}
