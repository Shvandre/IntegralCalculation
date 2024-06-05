#include "TestFunctions.h"
#include <math.h>
double f4(double x) {
    return log(x);
}
double f4_deriv(double x) {
    return 1/x;
}
double f5(double x) {
    return sin(x);
}
double f5_deriv(double x) {
    return cos(x);
}
double f6(double x) {
    return exp(x) - 30;
}
double f6_deriv(double x) {
    return exp(x);
}