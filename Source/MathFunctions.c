#include "MathFunctions.h"
#include <math.h>

double f1(double x) {
    return pow(2, x) + 1;
}

double f1_deriv(double x) {
    return log(2) * pow(2, x);
}

double f2(double x) {
    return x * x * x * x * x;
}

double f2_deriv(double x) {
    return 5 * x * x * x * x;
}

double f3(double x) {
    return (1 - x) / 3;
}

double f3_deriv(double x) {
    return -1 / 3;
}