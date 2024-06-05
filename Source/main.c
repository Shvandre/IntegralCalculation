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
        double absoluteInacr, relativeInacr;
        calcInnacuracy(actualRes, root_params.result, &absoluteInacr, &relativeInacr);
        fprintf(stderr, "Answer: %lf\nAbsolute inaccuracy: %lf\nRelative inaccuracy %lf%%\n", actualRes, absoluteInacr, relativeInacr*100);
        printf("%lf %lf %lf\n", actualRes, absoluteInacr, relativeInacr);
        return 0;
    }
    if(arguments.test_integral) {
        double actualRes = integral(integral_params.f, integral_params.a, integral_params.b,
                                    integral_params.eps2);
        double absoluteInacr, relativeInacr;
        calcInnacuracy(actualRes, integral_params.result, &absoluteInacr, &relativeInacr);
        fprintf(stderr, "Answer: %lf\nAbsolute inaccuracy: %lf\nRelative inaccuracy %lf%%\n", actualRes, absoluteInacr, relativeInacr*100);
        printf("%lf %lf %lf\n", actualRes, absoluteInacr, relativeInacr);
        return 0;
    }

    double eps1 = 1e-6;
    double root12 = root(f1, f2, 1, 2, eps1, f1_deriv, f2_deriv);
    double root23 = root(f2, f3, 0, 1, eps1, f2_deriv, f3_deriv);
    double root13 = root(f1, f3, -3, -2, eps1, f1_deriv, f3_deriv);
    printf("Root of f1(x) = f2(x) on [1, 2]: %lf\n", root12);
    printf("Root of f2(x) = f3(x) on [0, 1]: %lf\n", root23);
    printf("Root of f1(x) = f3(x) on [-3, -2]: %lf\n", root13);
    double eps2 = 1e-6;
    double integralF1 = integral(f1, root13, root12, eps2);
    double integralF2 = integral(f2, root23, root12, eps2);
    double integralF3 = integral(f3, root13, root23, eps2);
    printf("Integral F1 = %lf\nIntegral F2 = %lf\nIntegral F3 = %lf\n", integralF1, integralF2, integralF3);

    printf("Answer is: %lf\n", integralF1 - integralF2 - integralF3);

    return 0;
}