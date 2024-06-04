#include <stdio.h>
#include <math.h>
#include "Tools.h"
#include "MathFunctions.h"
#include "ArgParse.h"

int main(int argc, char **argv) {
    ParseArgs(argc, argv);
    if(arguments.test_root) {
        double actualRes = root(root_params.f, root_params.g, root_params.a, root_params.b,
                             root_params.eps1, root_params.f_deriv, root_params.g_deriv);
        printf("Root of f(x) = g(x) on [%lf, %lf]: %lf\n", root_params.a, root_params.b,
               actualRes);
        double absoluteInacr, relativeInacr;
        calcInnacuracy(actualRes, root_params.result, &absoluteInacr, &relativeInacr);
        fprintf(stderr, "Answer: %lf\nAbsolute inaccuracy: %lf\nRelative inaccuracy %lf%%\n", actualRes, absoluteInacr, relativeInacr*100);
        printf("%lf %lf %lf\n", actualRes, absoluteInacr, relativeInacr);
        return 0;
    }

    double eps = 1e-6;
    printf("Root of f1(x) = f2(x) on [1, 2]: %lf\n", root(f1, f2, 1, 2, eps, f1_deriv, f2_deriv));
    printf("Root of f2(x) = f3(x) on [0, 1]: %lf\n", root(f2, f3, 0, 1, eps, f2_deriv, f3_deriv));
    printf("Root of f1(x) = f3(x) on [-3, -2]: %lf\n", root(f1, f3, -3, -2, eps, f1_deriv, f3_deriv));
}