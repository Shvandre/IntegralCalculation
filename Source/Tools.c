#include "Tools.h"
#include <math.h>
#include <stdio.h>
#include "Defines.h"
#include "ArgParse.h"

static int sign(double x) {
    return x < 0 ? -1 : 1;
}
#define F(x) (f(x) - g(x))
#define F_deriv(x) (f_deriv(x) - g_deriv(x))


//Solve the equation f(x) = g(x) on the interval [a, b]
double root(mathFunc *f, mathFunc *g, double a, double b, double eps1,
            mathFunc *f_deriv, mathFunc *g_deriv) {
    //Implementing combined method
    if(arguments.root) {
        printf("Root of f(x) = g(x) on [%lf, %lf]\n", a, b);
    }
    int max_iter = 1000;
    while(max_iter--) {
        double c1 = (a * F(b) - b * F(a)) / (F(b) - F(a));
        if(fabs(F(c1)) < eps1) {
            if(arguments.root) {
                printf("Root found: %lf\n", c1);
            }
            if(arguments.iterations) {
                printf("Iterations needed: %d\n", 1000 - max_iter);
            }
            return c1;
        }
        int side = sign(F(c1)) * sign(F(a));
        double c2;
        if(side > 0) {
            a = c1;
            c2 = b - (F(b)) / (F_deriv(b));
            b = c2;
        } else {
            b = c1;
            c2 = a - (F(a)) / (F_deriv(a));
            a = c2;
        }
    }
    perror("Root not found");
    return NAN;
}
#undef F
#undef F_deriv

double integral(mathFunc* f, double a, double b, double eps2) {
    //implementing trapezoidal rule
    double n = 16;
    double h = (b - a) / n;
    double prevIntegralSum = (f(a) + f(b)) / 2;
    for (int i = 1; i < n; ++i) {
        prevIntegralSum += f(a + i * h);
    }
    double curIntegralSum = prevIntegralSum;
    do {
        prevIntegralSum = curIntegralSum;
        n *= 2;
        h /= 2;
        for(int i = 1; i < n; i += 2) {
            curIntegralSum += f(a + i * h);
        }
    } while(fabs(prevIntegralSum * 2 * h - curIntegralSum * h) / 3 >= eps2);
    return curIntegralSum * h;
}

void calcInnacuracy(double actual, double expected, double *absoluteInacr, double *relativeInacr) {
    *absoluteInacr = fabs(actual - expected);
    *relativeInacr = *absoluteInacr / expected;
}

