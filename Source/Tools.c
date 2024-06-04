#include "Tools.h"
#include <math.h>
#include <stdio.h>
#include "Defines.h"
#include "ArgParse.h"

#define F(x) (f(x) - g(x))
#define F_deriv(x) (f_deriv(x) - g_deriv(x))
static int sign(double x) {
    return x < 0 ? -1 : 1;
}


//Solve the equation f(x) = g(x) on the interval [a, b]
double root(mathFunc *f, mathFunc *g, double a, double b, double eps1,
            mathFunc *f_deriv, mathFunc *g_deriv) {
    //Implementing combined method
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