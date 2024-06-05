#pragma once
#include "Defines.h"

double root(mathFunc *f, mathFunc *g, double a, double b, double eps1,
            mathFunc *f_deriv, mathFunc *g_deriv);
double integral(mathFunc* f, double a, double b, double eps2);

void calcInnacuracy(double actual, double expected, double *absoluteInacr, double *relativeInacr);